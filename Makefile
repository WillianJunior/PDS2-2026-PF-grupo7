CC=g++
CFLAGS=-std=c++11 -Wall --coverage
TARGET=program
TARGET_TESTS=program_tests

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR =  ./include
TEST_DIR = ./tests
COVERAGE_DIR = ./coverage
THIRD_DIR = ./third_party

all: ${BUILD_DIR}/${TARGET}

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/Menu.o ${BUILD_DIR}/Administrador.o ${BUILD_DIR}/Carrinho.o ${BUILD_DIR}/Catalogo.o ${BUILD_DIR}/Cliente.o ${BUILD_DIR}/Compra.o ${BUILD_DIR}/Estoque.o ${BUILD_DIR}/Produto.o ${BUILD_DIR}/Usuario.o ${BUILD_DIR}/animacao.o ${BUILD_DIR}/desenhos.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/Menu.o: ${INCLUDE_DIR}/Controle/Menu.hpp ${SRC_DIR}/Controle/Menu.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Controle -c ${SRC_DIR}/Controle/Menu.cpp -o ${BUILD_DIR}/Menu.o

${BUILD_DIR}/Usuario.o: ${INCLUDE_DIR}/Usuario.hpp ${SRC_DIR}/Usuario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Usuario.cpp -o ${BUILD_DIR}/Usuario.o

${BUILD_DIR}/Administrador.o: ${INCLUDE_DIR}/Usuario.hpp ${INCLUDE_DIR}/Administrador.hpp ${SRC_DIR}/Administrador.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Administrador.cpp -o ${BUILD_DIR}/Administrador.o

${BUILD_DIR}/Produto.o: ${INCLUDE_DIR}/Produto.hpp ${SRC_DIR}/Produto.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Produto.cpp -o ${BUILD_DIR}/Produto.o

${BUILD_DIR}/Carrinho.o: ${INCLUDE_DIR}/Produto.hpp ${INCLUDE_DIR}/Carrinho.hpp ${SRC_DIR}/Carrinho.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Carrinho.cpp -o ${BUILD_DIR}/Carrinho.o

${BUILD_DIR}/Catalogo.o: ${INCLUDE_DIR}/Produto.hpp ${INCLUDE_DIR}/Catalogo.hpp ${SRC_DIR}/Catalogo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Catalogo.cpp -o ${BUILD_DIR}/Catalogo.o

${BUILD_DIR}/Cliente.o: ${INCLUDE_DIR}/Carrinho.hpp ${INCLUDE_DIR}/Compra.hpp ${INCLUDE_DIR}/Usuario.hpp ${SRC_DIR}/Cliente.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Cliente.cpp -o ${BUILD_DIR}/Cliente.o

${BUILD_DIR}/Compra.o: ${INCLUDE_DIR}/Produto.hpp ${INCLUDE_DIR}/Compra.hpp ${SRC_DIR}/Compra.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Compra.cpp -o ${BUILD_DIR}/Compra.o

${BUILD_DIR}/Estoque.o: ${INCLUDE_DIR}/Estoque.hpp ${SRC_DIR}/Estoque.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Estoque.cpp -o ${BUILD_DIR}/Estoque.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/Controle/Menu.hpp ${INCLUDE_DIR}/Animacao/animacao.hpp ${INCLUDE_DIR}/*.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Animacao/ -I ${INCLUDE_DIR}/Controle/ -I ${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

################################# TESTES ######################################################

${TEST_DIR}/test_Administrador.o: ${TEST_DIR}/test_Administrador.cpp
	${CC} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR} -c ${TEST_DIR}/test_Administrador.cpp -o ${TEST_DIR}/test_Administrador.o

${TEST_DIR}/test_Carrinho.o: ${TEST_DIR}/test_Carrinho.cpp
	${CC} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR} -c ${TEST_DIR}/test_Carrinho.cpp -o ${TEST_DIR}/test_Carrinho.o

${TEST_DIR}/test_Catalogo.o: ${TEST_DIR}/test_Catalogo.cpp
	${CC} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR} -c ${TEST_DIR}/test_Catalogo.cpp -o ${TEST_DIR}/test_Catalogo.o

${TEST_DIR}/test_Cliente.o: ${TEST_DIR}/test_Cliente.cpp
	${CC} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR} -c ${TEST_DIR}/test_Cliente.cpp -o ${TEST_DIR}/test_Cliente.o

${TEST_DIR}/test_Compra.o: ${TEST_DIR}/test_Compra.cpp
	${CC} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR} -c ${TEST_DIR}/test_Compra.cpp -o ${TEST_DIR}/test_Compra.o

${TEST_DIR}/test_Estoque.o: ${TEST_DIR}/test_Estoque.cpp
	${CC} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR} -c ${TEST_DIR}/test_Estoque.cpp -o ${TEST_DIR}/test_Estoque.o

${TEST_DIR}/test_Produto.o: ${TEST_DIR}/test_Produto.cpp
	${CC} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR} -c ${TEST_DIR}/test_Produto.cpp -o ${TEST_DIR}/test_Produto.o

${TEST_DIR}/test_Usuario.o: ${TEST_DIR}/test_Usuario.cpp
	${CC} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR} -c ${TEST_DIR}/test_Usuario.cpp -o ${TEST_DIR}/test_Usuario.o

${TEST_DIR}/main_tests.o: ${TEST_DIR}/main_tests.cpp
	${CC} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR} -I ${INCLUDE_DIR} -c ${TEST_DIR}/main_tests.cpp -o ${TEST_DIR}/main_tests.o

${TEST_DIR}/test_Menu.o: ${TEST_DIR}/test_Menu.cpp
	${CC} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR}/Controle -c ${TEST_DIR}/test_Menu.cpp -o ${TEST_DIR}/test_Menu.o


############################# ANIMAÇÃO ##########################################################

${BUILD_DIR}/animacao.o: ${INCLUDE_DIR}/Animacao/animacao.hpp ${SRC_DIR}/Animacao/animacao.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Animacao -c ${SRC_DIR}/Animacao/animacao.cpp -o ${BUILD_DIR}/animacao.o

${BUILD_DIR}/desenhos.o: ${INCLUDE_DIR}/Animacao/desenhos.hpp ${SRC_DIR}/Animacao/desenhos.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Animacao -c ${SRC_DIR}/Animacao/desenhos.cpp -o ${BUILD_DIR}/desenhos.o

##################################################################################################
tests: all ${TEST_DIR}/test_Menu.o ${TEST_DIR}/test_Administrador.o ${TEST_DIR}/test_Carrinho.o ${TEST_DIR}/test_Catalogo.o ${TEST_DIR}/test_Cliente.o ${TEST_DIR}/test_Compra.o ${TEST_DIR}/test_Estoque.o ${TEST_DIR}/test_Produto.o ${TEST_DIR}/test_Usuario.o ${TEST_DIR}/main_tests.o
	${CC} ${CFLAGS} -o ${TEST_DIR}/${TARGET_TESTS} ${BUILD_DIR}/Menu.o ${BUILD_DIR}/Administrador.o ${BUILD_DIR}/Carrinho.o ${BUILD_DIR}/Catalogo.o ${BUILD_DIR}/Cliente.o ${BUILD_DIR}/Compra.o  ${BUILD_DIR}/Estoque.o ${BUILD_DIR}/Produto.o ${BUILD_DIR}/Usuario.o  ${TEST_DIR}/*.o

run_tests: tests
	-./${TEST_DIR}/${TARGET_TESTS}

run: all
	find ./build -name "*.gcda" -delete #Apaga os arquivos *.gcda da última build para não gerar inconsistências
	./${BUILD_DIR}/${TARGET}

coverage: run_tests
	gcovr -r . --exclude="third_party/doctest.h"
	gcovr -r . --exclude="third_party/doctest.h" -b

html-coverage: run_tests
	gcovr -r . --exclude="third_party/doctest.h" --html --html-details -o ${COVERAGE_DIR}/relatorio.html

documentation:
	doxygen Doxyfile

clean:
	rm -f ${BUILD_DIR}/*
	rm -f ${TEST_DIR}/*.o ${TEST_DIR}/*.gcda ${TEST_DIR}/*.gcno ${TEST_DIR}/${TARGET_TESTS}
	rm -f ${COVERAGE_DIR}/*
	rm -rf ./do

clean-docs:
	rm -rf ./docs