%{
#include "linguagemUtils.h"
#include "validacoes.h"

extern void yyerror();
extern int yylex();
extern char *yytext;
extern int yylineno;

extern char TiposDeDados[100];

extern void listarIdentificadores();
extern void limparTiposDeDados();
extern void salvarTipoDeDados(const char *);
extern char *obterTiposDeDados();
extern bool duplicado(char *);
extern char *obterIdentificador(char []);
extern void salvarIdentificador(char *, char *);
extern void salvarIdentificadorEValor(char *, char *, char *);
extern void atualizarValor(char *, char *);
extern char *obterValor(char *);
extern void erroAtribuicao(char *);
extern void erroIdentificadorInexistente(char *);
extern void erroIdentificadorDuplicado(char *);
bool atribucaoValida(char *);

char *floatToAscii(float);

int noDeIdentificadoresDeVetor=0;
char identificadorExtraido[100][100];
%}

%define parse.lac full
%define parse.error verbose

%union {
	float numVal;
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
%type <numVal> EXPRESSAO_NUMERICA
%type <txtVal> FUNCAO_DECLARACAO

%%

DECLARACAO: PRINT ID PONTO_VIRGULA { printf("\n%s\n", obterValor($2)); }
| PRINT EXPRESSAO_NUMERICA PONTO_VIRGULA { printf("\n%s\n", $2); }
| SAIR PONTO_VIRGULA { exit(EXIT_SUCCESS); }
| EXPRESSAO PONTO_VIRGULA { limparTiposDeDados(); }
| ATRIBUICAO PONTO_VIRGULA { limparTiposDeDados(); }
| FUNCAO_DECLARACAO PONTO_VIRGULA
| DECLARACAO EXPRESSAO PONTO_VIRGULA { limparTiposDeDados(); }
| DECLARACAO FUNCAO_DECLARACAO PONTO_VIRGULA
| error '>' {};

EXPRESSAO: TIPO_DE_DADOS ID {
	if (!duplicado($2)) {
    	salvarIdentificador($2, obterTiposDeDados());
        salvarTipoDeDados($1);
    } else {
        erroIdentificadorDuplicado($2);
    }
}
| TIPO_DE_DADOS ID IGUAL VALOR_NUMERICO {
	if(!duplicado($2)) {
        salvarIdentificadorEValor($2, obterTiposDeDados(), floatToAscii($4));
        salvarTipoDeDados($1);
    } else {
        erroIdentificadorDuplicado($2);
    }
}
| TIPO_DE_DADOS ID IGUAL VALOR_TEXTUAL {
	if(!duplicado($2)) {
        salvarIdentificadorEValor($2, obterTiposDeDados(), $4);
        salvarTipoDeDados($1);
    } else {
        erroIdentificadorDuplicado($2);
    }
}
| EXPRESSAO IGUAL ABRE_CHAVE LISTA_DE_PARAMETROS FECHA_CHAVE
| error '>' {};

ATRIBUICAO: ID IGUAL VALOR_NUMERICO { atualizarValor($1, floatToAscii($3)); }
| ID IGUAL VALOR_TEXTUAL { atualizarValor($1, $3); }
| ID IGUAL EXPRESSAO_NUMERICA {	atualizarValor($1, floatToAscii($3)); }
| ID IGUAL ID {	atualizarValor($1, obterValor($3)); };

EXPRESSAO_NUMERICA: VALOR_NUMERICO SOMA VALOR_NUMERICO { $$ = $1 + $3; }
| VALOR_NUMERICO SUBTRACAO VALOR_NUMERICO { $$ = $1 - $3; }
| VALOR_NUMERICO DIVISAO VALOR_NUMERICO { $$ = $1 / $3; }
| VALOR_NUMERICO MULTIPLICACAO VALOR_NUMERICO { $$ = $1 * $3; };

VALOR: VALOR_NUMERICO {
    if(!atribucaoValida("number")) {
        erroAtribuicao(floatToAscii($1));
    }
}
| VALOR_TEXTUAL {
    if(!atribucaoValida("text")) {
        erroAtribuicao($1);
    }
};

LISTA_DE_PARAMETROS: ID
| VALOR
| LISTA_DE_PARAMETROS VIRGULA VALOR
| VALOR IGUAL VALOR { yyerror("Erro: atribuindo um numero a outro"); }
| error '>' {};

FUNCAO_DECLARACAO: TIPO_DE_DADOS ID ABRE_PARENTESES LISTA_DE_TIPOS_DE_DADOS FECHA_PARENTESES {
    if(!duplicado($2)) {
	salvarIdentificador($2, obterTiposDeDados());
    } else {
	erroIdentificadorDuplicado($2);
    }
};

LISTA_DE_TIPOS_DE_DADOS: TIPO_DE_DADOS
| LISTA_DE_TIPOS_DE_DADOS VIRGULA TIPO_DE_DADOS;

%%

int main() {
    yyparse();
    printf("Sem erros!!\n");
    return 0;
}