%{
#include "../../headers/linguagemUtils.h"
#include "../../headers/validacoes.h"

extern void yyerror();
extern int yylex();
extern char *yytext;
extern int yylineno;

extern char TiposDeDados[100];

extern void listarIdentificadores();
extern void limparTiposDeDados();
extern void salvarTipoDeDados(char *);
extern char *obterTiposDeDados();
extern bool duplicado(char *);
extern char *obterIdentificador(char []);
extern void salvarIdentificador(char *, char *);
extern void salvarIdentificador(char *, char *, char *);
extern void atualizarValor(char *, char *);
extern char *obterValor(char *);
extern void erroAtribuicao(char *);
extern void erroIdentificadorInexistente(char *);
extern void erroIdentificadorDuplicado(char *);
bool atribucaoValida(char *);

int noDeIdentificadoresDeVetor=0;
char identificadorExtraido[100][100];
%}

%define parse.lac full
%define parse.error verbose

%union {
	double numVal;
	char *tipoDeDados;
	char *txtVal;
}

%token VIRGULA APOSTROFE PONTO_VIRGULA IGUAL SOMA SUBTRACAO DIVISAO MULTIPLICACAO
%token ABRE_PARENTESES FECHA_PARENTESES ABRE_CHAVE FECHA_CHAVE ABRE_COLCHETE FECHA_COLCHETE
%token IF ELSE WHILE FOR
%token PRINT SAIR

%token <numVal> VALOR_NUMERICO
%token <txtVal> VALOR_TEXTUAL
%token <tipoDeDados> TIPO_DE_DADOS
%token <txtVal> ID

%type <txtVal> DECLARACAO
%type <txtVal> EXPRESSAO
%type <txtVal> FUNCAO_DECLARACAO

%%

DECLARACAO:
PRINT EXPRESSAO PONTO_VIRGULA { printf("\n%s\n", $2); }
| PRINT ID PONTO_VIRGULA { printf("\n%s\n", $2); }
| DECLARACAO PRINT EXPRESSAO_NUMERICA PONTO_VIRGULA { printf("\n%s\n", $3); }
| DECLARACAO PRINT ID PONTO_VIRGULA { printf("\n%s\n", obterValor($3)); }
| SAIR PONTO_VIRGULA { exit(EXIT_SUCCESS); }
| DECLARACAO SAIR PONTO_VIRGULA { exit(EXIT_SUCCESS); }
| EXPRESSAO PONTO_VIRGULA { limparTiposDeDados(); }
| ATRIBUICAO PONTO_VIRGULA { limparTiposDeDados(); }
| FUNCAO_DECLARACAO PONTO_VIRGULA
| DECLARACAO EXPRESSAO PONTO_VIRGULA { limparTiposDeDados(); }
| DECLARACAO FUNCAO_DECLARACAO PONTO_VIRGULA
| error '>' {};

EXPRESSAO:
TIPO_DE_DADOS ID {
if (!duplicado($2)) {
    salvarIdentificador($2, obterTiposDeDados());
        salvarTipoDeDados($1);
    } else {
        erroIdentificadorDuplicado($2);
    }
}
| EXPRESSAO IGUAL VALOR {
    if(!duplicado($2)) {
        salvarIdentificador($2, obterTiposDeDados(), $4);
        salvarTipoDeDados($1);
    } else {
        erroIdentificadorDuplicado($2);
    };
}
| EXPRESSAO IGUAL ABRE_CHAVE LISTA_DE_PARAMETROS FECHA_CHAVE
| error '>' {};

ATRIBUICAO: 
ID IGUAL VALOR { atualizarValor($1, $3); }
| ID IGUAL EXPRESSAO_NUMERICA {	atualizarValor($1, $3); }
| ID IGUAL ID {	atualizarValor($1, obterValor($3)); }
| ID IGUAL ID;

EXPRESSAO_NUMERICA:
VALOR_NUMERICO SOMA VALOR_NUMERICO { $$ = $1 + $3; }
| VALOR_NUMERICO SUBTRACAO VALOR_NUMERICO { $$ = $1 - $3; }
| VALOR_NUMERICO DIVISAO VALOR_NUMERICO { $$ = $1 / $3; }
| VALOR_NUMERICO MULTIPLICACAO VALOR_NUMERICO { $$ = $1 * $3; }

VALOR:
VALOR_NUMERICO {
    if(!atribucaoValida("number")) {
        erroAtribuicao($1);
    }
}
| VALOR_TEXTUAL {
    if(!atribucaoValida("text")) {
        erroAtribuicao($1);
    }
};

LISTA_DE_PARAMETROS:
ID
| VALOR
| LISTA_DE_PARAMETROS VIRGULA VALOR
| VALOR IGUAL VALOR { yyerror("Erro: atribuindo um numero a outro"); }
| error '>' {};

FUNCAO_DECLARACAO:
TIPO_DE_DADOS ID ABRE_PARENTESES LISTA_DE_TIPOS_DE_DADOS FECHA_PARENTESES {
    if(!duplicado($2)) {
	salvarIdentificador($2, obterTiposDeDados());
    } else {
	erroIdentificadorDuplicado($2);
    }
};

LISTA_DE_TIPOS_DE_DADOS:
TIPO_DE_DADOS
| LISTA_DE_TIPOS_DE_DADOS VIRGULA TIPO_DE_DADOS;

%%

int main() {
    yyparse();
    printf("Sem erros!!\n");
    return 0;
}