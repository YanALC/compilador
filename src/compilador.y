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
extern char *obterTipoDeDados(char *);
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

%start LINHA

%token VIRGULA APOSTROFE PONTO_VIRGULA IGUAL 
%token SOMA SUBTRACAO DIVISAO MULTIPLICACAO INC_DEC
%token IGUAL_IGUAL DIFERENTE NEGACAO MENOR MAIOR MENOR_IGUAL MAIOR_IGUAL AND OR
%token ABRE_PARENTESES FECHA_PARENTESES ABRE_CHAVE FECHA_CHAVE ABRE_COLCHETE FECHA_COLCHETE
%token IF ELSE WHILE FOR
%token PRINT SAIR

%token <numVal> VALOR_NUMERICO
%token <txtVal> VALOR_TEXTUAL
%token <tipoDeDados> TIPO_DE_DADOS
%token <txtVal> ID

%type <txtVal> TOKENS
%type <txtVal> DECLARACAO
%type <txtVal> EXPRESSAO
%type <numVal> EXPRESSAO_NUMERICA
%type <txtVal> FUNCAO_DECLARACAO

%left SOMA SUBTRACAO
%left MULTIPLICACAO DIVISAO

%%

LINHA: DECLARACAO
| FUNCAO_PRINT
| FUNCOES_RESERVADAS
| LINHA DECLARACAO
| LINHA FUNCAO_PRINT
| LINHA FUNCOES_RESERVADAS
| SAIR PONTO_VIRGULA { exit(EXIT_SUCCESS); };

FUNCAO_PRINT: PRINT ID PONTO_VIRGULA { printf("%s \n", obterValor($2)); }
| PRINT EXPRESSAO_NUMERICA PONTO_VIRGULA { printf("%s \n", floatToAscii($2)); }
| PRINT VALOR_NUMERICO PONTO_VIRGULA { printf("%s \n", floatToAscii($2)); }
| PRINT VALOR_TEXTUAL PONTO_VIRGULA { printf("%s \n", $2); };

DECLARACAO: EXPRESSAO PONTO_VIRGULA { limparTiposDeDados(); }
| ATRIBUICAO PONTO_VIRGULA {;}
| FUNCAO_DECLARACAO PONTO_VIRGULA
| DECLARACAO EXPRESSAO PONTO_VIRGULA { limparTiposDeDados(); }
| DECLARACAO ATRIBUICAO PONTO_VIRGULA {;}
| DECLARACAO FUNCAO_DECLARACAO PONTO_VIRGULA
| error '>' {};

EXPRESSAO: TIPO_DE_DADOS ID {
	if (!duplicado($2)) {
    	salvarIdentificador($2, $1);
        salvarTipoDeDados($1);
    } else {
        erroIdentificadorDuplicado($2);
    }
}
| TIPO_DE_DADOS ID IGUAL VALOR_NUMERICO {
	if(duplicado($2)) {
		erroIdentificadorDuplicado($2);
	} else if (strcmp($1, "number") != 0) {
		erroAtribuicao($1);
	} else {
        salvarIdentificadorEValor($2, $1, floatToAscii($4));
        salvarTipoDeDados($1);
    }
}
| TIPO_DE_DADOS ID IGUAL EXPRESSAO_NUMERICA {
	if(duplicado($2)) {
		erroIdentificadorDuplicado($2);
	} else if (strcmp($1, "number") != 0) {
		erroAtribuicao($1);
	} else {
        salvarIdentificadorEValor($2, $1, floatToAscii($4));
        salvarTipoDeDados($1);
    }
}
| TIPO_DE_DADOS ID IGUAL VALOR_TEXTUAL {
	if(duplicado($2)) {
		erroIdentificadorDuplicado($2);
	} else if (strcmp($1, "text") != 0) {
		erroAtribuicao($1);
	} else {
        salvarIdentificadorEValor($2, $1, $4);
        salvarTipoDeDados($1);
    }
}
| TIPO_DE_DADOS ID IGUAL ID {
	if(duplicado($2)) {
		erroIdentificadorDuplicado($2);
	} else if(strcmp($1, obterTipoDeDados($4)) != 0) {
		erroAtribuicao($1);
	} else {
        salvarIdentificadorEValor($2, $1, obterValor($4));
        salvarTipoDeDados($1);
    }
}
| EXPRESSAO IGUAL ABRE_CHAVE LISTA_DE_PARAMETROS FECHA_CHAVE
| error '>' {};

ATRIBUICAO: ID IGUAL VALOR_NUMERICO {
	char *tipoDeDados = obterTipoDeDados($1);
	char *number = "number";
	if(strcmp(tipoDeDados, number) == 0) {
    	atualizarValor($1, floatToAscii($3)); 
	} else {
		erroAtribuicao(tipoDeDados);
	}
}
| ID IGUAL VALOR_TEXTUAL {
	char *tipoDeDados = obterTipoDeDados($1);
	char *text = "text";
	if(strcmp(tipoDeDados, text) == 0) {
    	atualizarValor($1, $3); 
	} else {
		erroAtribuicao(tipoDeDados);
	}
}
| ID IGUAL EXPRESSAO_NUMERICA {
	char *tipoDeDados = obterTipoDeDados($1);
	if(strcmp(tipoDeDados, "number") == 0) {
    	atualizarValor($1, floatToAscii($3)); 
	} else {
		erroAtribuicao(tipoDeDados);
	}
}
| ID IGUAL ID {
	if(strcmp(obterTipoDeDados($1), obterTipoDeDados($3)) == 0) {
    	atualizarValor($1, obterValor($3)); 
	} else {
		erroAtribuicao(obterTipoDeDados($3));
	}
};

FUNCOES_RESERVADAS: CLAUSULA_IF
| CLAUSULA_IF ELSE CLAUSULA_IF
| CLAUSULA_IF ELSE ABRE_CHAVE LINHA FECHA_CHAVE
| FOR ABRE_PARENTESES LISTA_VARS PONTO_VIRGULA OP_LOGICA PONTO_VIRGULA ID INC_DEC FECHA_PARENTESES ABRE_CHAVE LINHA FECHA_CHAVE
| WHILE ABRE_PARENTESES OP_LOGICA FECHA_PARENTESES ABRE_CHAVE LINHA FECHA_CHAVE;

CLAUSULA_IF: IF ABRE_PARENTESES OP_LOGICA FECHA_PARENTESES ABRE_CHAVE LINHA FECHA_CHAVE;

LISTA_VARS: ATRIBUICAO
| EXPRESSAO
| EXPRESSAO VIRGULA EXPRESSAO
| ATRIBUICAO VIRGULA ATRIBUICAO;

TOKENS: ID { $$ = obterValor($1); }
| VALOR_NUMERICO { $$ = floatToAscii($1); }
| EXPRESSAO_NUMERICA { $$ = floatToAscii($1); }
| VALOR_TEXTUAL { $$ = $1; };

OP_LOGICA: TOKENS IGUAL_IGUAL TOKENS
| TOKENS DIFERENTE TOKENS 
| TOKENS MAIOR TOKENS 
| TOKENS MAIOR_IGUAL TOKENS 
| TOKENS MENOR_IGUAL TOKENS
| OP_LOGICA IGUAL_IGUAL OP_LOGICA;
| OP_LOGICA DIFERENTE OP_LOGICA;
| OP_LOGICA AND OP_LOGICA;
| OP_LOGICA OR OP_LOGICA;

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