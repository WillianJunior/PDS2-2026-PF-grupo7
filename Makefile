CC = g++
CFLAGS = -Wall -Iinclude -MMD -MP
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = tests
TEST_BUILD_DIR = $(BUILD_DIR)/tests

SOURCES = $(shell find $(SRC_DIR) -name "*.cpp")
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
DEPS = $(OBJECTS:.o=.d)

TEST_SOURCES = $(shell find $(TEST_DIR) -name "*.cpp")
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.cpp,$(TEST_BUILD_DIR)/%.o,$(TEST_SOURCES))
TEST_DEPS = $(TEST_OBJECTS:.o=.d)
TEST_BINS = $(TEST_OBJECTS:.o=)

TARGET = app

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Each test file defines DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN itself
$(TEST_BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -DDOCTEST_CONFIG_IMPLEMENT_WITH_MAIN -c $< -o $@

# Link each test binary against its corresponding class .o only
# e.g. build/tests/test_foo links with build/foo.o
$(TEST_BUILD_DIR)/%: $(TEST_BUILD_DIR)/%.o
	$(eval CLASS := $(patsubst test_%,%,$(notdir $@)))
	$(eval CLASS_OBJ := $(BUILD_DIR)/$(CLASS).o)
	$(CC) $(CFLAGS) -o $@ $< $(if $(wildcard $(CLASS_OBJ)),$(CLASS_OBJ),)

-include $(DEPS)
-include $(TEST_DEPS)

test: $(TEST_BINS)
	@echo "Running all tests..."
	@PASS=0; FAIL=0; \
	for t in $(TEST_BINS); do \
		echo "--- $$t ---"; \
		if $$t; then \
			PASS=$$((PASS+1)); \
		else \
			FAIL=$$((FAIL+1)); \
		fi; \
	done; \
	echo ""; \
	echo "Results: $$PASS passed, $$FAIL failed."; \
	[ $$FAIL -eq 0 ]

.PHONY: clean test
clean:
	rm -rf $(BUILD_DIR) $(TARGET)