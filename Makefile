# Define qual compilador será usado.
# "g++" é o compilador padrão para programas em C++.
CC = g++

# Flags (opções) passadas para o compilador.
# -Wall -> mostra avisos importantes durante a compilação.
# -Iinclude -> diz ao compilador que os arquivos .h estão na pasta "include".
CFLAGS = -Wall -Iinclude

# Flags usadas para gerar relatório de cobertura de testes.
# Isso permite medir quais partes do código foram executadas nos testes.
COVFLAGS = --coverage -fprofile-arcs -ftest-coverage

# Pasta onde ficam os arquivos fonte (.cpp) do programa principal.
SRC_DIR = src

# Pasta onde os arquivos compilados (.o) serão armazenados.
BUILD_DIR = build

# Procura automaticamente todos os arquivos .cpp dentro da pasta src.
# Exemplo:
# src/main.cpp
# src/utils/math.cpp
SOURCES = $(shell find $(SRC_DIR) -name "*.cpp")

# Converte os arquivos .cpp em arquivos .o dentro da pasta build.
# Exemplo:
# src/main.cpp -> build/main.o
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Pasta onde ficam os testes.
TEST_DIR = tests

# Pasta onde os arquivos compilados dos testes serão salvos.
TEST_BUILD_DIR = $(BUILD_DIR)/tests

# Procura automaticamente todos os arquivos .cpp da pasta tests.
TEST_SOURCES = $(shell find $(TEST_DIR) -name "*.cpp")

# Converte os arquivos de teste .cpp em arquivos .o.
# Exemplo:
# tests/test_math.cpp -> build/tests/test_math.o
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.cpp,$(TEST_BUILD_DIR)/%.o,$(TEST_SOURCES))

# Remove a extensão .o dos testes para criar os executáveis.
# Exemplo:
# build/tests/test_math.o -> build/tests/test_math
TEST_BINS = $(TEST_OBJECTS:.o=)

# Nome do executável final do programa principal.
TARGET = app


# =========================================================
# REGRA PRINCIPAL
# =========================================================

# Diz que o executável "app" depende dos arquivos objeto (.o).
# Ou seja: antes de criar "app", o Makefile precisa compilar os .o.
$(TARGET): $(OBJECTS)

	# Compila e junta todos os arquivos .o em um executável chamado "app".
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)


# =========================================================
# COMPILAÇÃO DOS ARQUIVOS DO PROGRAMA PRINCIPAL
# =========================================================

# Regra genérica para transformar arquivos .cpp em .o.
# Exemplo:
# src/main.cpp -> build/main.o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp

	# Cria automaticamente a pasta necessária.
	# mkdir -p evita erro caso a pasta já exista.
	mkdir -p $(dir $@)

	# Compila o arquivo .cpp para gerar um arquivo .o.
	#
	# $< = arquivo fonte atual
	# $@ = arquivo de saída
	$(CC) $(CFLAGS) $(COVFLAGS) -c $< -o $@


# =========================================================
# COMPILAÇÃO DOS TESTES
# =========================================================

# Regra para compilar arquivos de teste.
# Exemplo:
# tests/test_math.cpp -> build/tests/test_math.o
$(TEST_BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp

	# Cria a pasta necessária para os objetos dos testes.
	mkdir -p $(dir $@)

	# Compila o arquivo de teste.
	$(CC) $(CFLAGS) $(COVFLAGS) -c $< -o $@


# =========================================================
# CRIAÇÃO DOS EXECUTÁVEIS DE TESTE
# =========================================================

# Cria o executável de cada teste.
#
# $(filter-out $(BUILD_DIR)/main.o, $(OBJECTS))
# remove o main.o do programa principal,
# porque os testes normalmente possuem seu próprio main().
$(TEST_BUILD_DIR)/%: $(TEST_BUILD_DIR)/%.o $(filter-out $(BUILD_DIR)/main.o, $(OBJECTS))

	# Gera o executável do teste.
	#
	# $@ = nome do executável final
	# $^ = lista de dependências
	$(CC) $(CFLAGS) $(COVFLAGS) -o $@ $^


# =========================================================
# EXECUTAR TESTES
# =========================================================

# Comando:
# make test
#
# Primeiro garante que todos os testes foram compilados.
test: $(TEST_BINS)

	# Executa cada teste automaticamente.
	#
	# $$t = variável do shell
	# true no final evita que o make pare no primeiro erro.
	@for t in $(TEST_BINS); do $$t; done; true


# =========================================================
# GERAR RELATÓRIO DE COBERTURA
# =========================================================

# Comando:
# make coverage
coverage: clean $(TEST_BINS)

	# Executa todos os testes.
	@for t in $(TEST_BINS); do $$t; done; true

	# Gera um relatório HTML de cobertura usando gcovr.
	#
	# --root .          -> define a raiz do projeto
	# --filter src/     -> analisa apenas arquivos da pasta src
	# --html            -> gera saída HTML
	# --html-details    -> cria relatório detalhado
	# -o coverage.html  -> nome do arquivo de saída
	gcovr --root . --filter src/ --html --html-details -o coverage.html

	# Mostra mensagem no terminal.
	@echo "Coverage report saved to coverage.html"


# =========================================================
# TARGETS ESPECIAIS
# =========================================================

# .PHONY diz ao make que esses nomes NÃO são arquivos reais.
# Eles são comandos.
.PHONY: clean test coverage


# =========================================================
# LIMPEZA DOS ARQUIVOS GERADOS
# =========================================================

# Comando:
# make clean
clean:

	# Remove:
	# - pasta build
	# - executável app
	# - arquivos de cobertura
	# - arquivos temporários do gcov
	rm -rf $(BUILD_DIR) $(TARGET) coverage.html coverage*.html coverage.css *.gcov *.gcno *.gcda