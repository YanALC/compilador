/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_COMPILADOR_TAB_H_INCLUDED
# define YY_YY_COMPILADOR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VIRGULA = 258,
    APOSTROFE = 259,
    PONTO_VIRGULA = 260,
    IGUAL = 261,
    SOMA = 262,
    SUBTRACAO = 263,
    DIVISAO = 264,
    MULTIPLICACAO = 265,
    INC_DEC = 266,
    IGUAL_IGUAL = 267,
    DIFERENTE = 268,
    NEGACAO = 269,
    MENOR = 270,
    MAIOR = 271,
    MENOR_IGUAL = 272,
    MAIOR_IGUAL = 273,
    AND = 274,
    OR = 275,
    ABRE_PARENTESES = 276,
    FECHA_PARENTESES = 277,
    ABRE_CHAVE = 278,
    FECHA_CHAVE = 279,
    ABRE_COLCHETE = 280,
    FECHA_COLCHETE = 281,
    IF = 282,
    ELSE = 283,
    WHILE = 284,
    FOR = 285,
    PRINT = 286,
    SAIR = 287,
    VALOR_NUMERICO = 288,
    VALOR_TEXTUAL = 289,
    TIPO_DE_DADOS = 290,
    ID = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 37 "compilador.y" /* yacc.c:1910  */

	float numVal;
	char *tipoDeDados;
	char *txtVal;

#line 97 "compilador.tab.h" /* yacc.c:1910  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILADOR_TAB_H_INCLUDED  */
