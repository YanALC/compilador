cmake_minimum_required(VERSION 3.13)
project(compilador C)

set(CMAKE_C_STANDARD 11)

include_directories(headers)
include_directories(src/lex)
include_directories(src/yacc)

add_executable(compilador
		headers/linguagemUtils.h
		headers/validacoes.h
		src/lex/lex.yy.c
		src/yacc/compilador.tab.c
		src/yacc/compilador.tab.h)
