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
extern bool existeId(char *);
extern char *obterIdentificador(char []);
extern void salvarIdentificador(char *, char *);
extern void salvarIdentificadorEValor(char *, char *, char *);
extern void atualizarValor(char *, char *);
extern char *obterValor(char *);
extern void erroAtribuicao(char *, char *);
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

LINHA: {;}
| DECLARACAO
| FUNCAO_PRINT
| FUNCOES_RESERVADAS
| SAIR PONTO_VIRGULA { exit(EXIT_SUCCESS); }
| LINHA DECLARACAO
| LINHA FUNCAO_PRINT
| LINHA FUNCOES_RESERVADAS
| LINHA SAIR PONTO_VIRGULA { exit(EXIT_SUCCESS); }
| error '>' {};

FUNCAO_PRINT: PRINT ID PONTO_VIRGULA { printf("%s \n", obterValor($2)); }
| PRINT EXPRESSAO_NUMERICA PONTO_VIRGULA { printf("%s \n", floatToAscii($2)); }
| PRINT VALOR_NUMERICO PONTO_VIRGULA { printf("%s \n", floatToAscii($2)); }
| PRINT VALOR_TEXTUAL PONTO_VIRGULA { printf("%s \n", $2); };

DECLARACAO: EXPRESSAO PONTO_VIRGULA {;}
| ATRIBUICAO PONTO_VIRGULA {;}
| FUNCAO_DECLARACAO PONTO_VIRGULA {;}
| DECLARACAO EXPRESSAO PONTO_VIRGULA {;}
| DECLARACAO ATRIBUICAO PONTO_VIRGULA {;}
| DECLARACAO FUNCAO_DECLARACAO PONTO_VIRGULA {;}
| error '>' {;};

EXPRESSAO: TIPO_DE_DADOS ID {
	if (!existeId($2)) {
    	salvarIdentificador($2, $1);
        salvarTipoDeDados($1);
    } else {
        erroIdentificadorDuplicado($2);
    }
}
| TIPO_DE_DADOS ID IGUAL VALOR_NUMERICO {
	if(existeId($2)) {
		erroIdentificadorDuplicado($2);
	} else if (strcmp($1, "number") != 0) {
		erroAtribuicao($1, "number");
	} else {
        salvarIdentificadorEValor($2, $1, floatToAscii($4));
    //    salvarTipoDeDados($1);
    }
}
| TIPO_DE_DADOS ID IGUAL EXPRESSAO_NUMERICA {
	if(existeId($2)) {
		erroIdentificadorDuplicado($2);
	} else if (strcmp($1, "number") != 0) {
		erroAtribuicao($1, "number");
	} else {
        salvarIdentificadorEValor($2, $1, floatToAscii($4));
    //    salvarTipoDeDados($1);
    }
}
| TIPO_DE_DADOS ID IGUAL VALOR_TEXTUAL {
	if(existeId($2)) {
		erroIdentificadorDuplicado($2);
	} else if (strcmp($1, "text") != 0) {
		erroAtribuicao($1, "text");
	} else {
        salvarIdentificadorEValor($2, $1, $4);
    //    salvarTipoDeDados($1);
    }
}
| TIPO_DE_DADOS ID IGUAL ID {
	char *tipoFornecido = obterTipoDeDados($4); 
	if(existeId($2)) {
		erroIdentificadorDuplicado($2);
	} else if(strcmp($1, obterTipoDeDados($4)) != 0) {
		erroAtribuicao($1, tipoFornecido);
	} else {
        salvarIdentificadorEValor($2, $1, obterValor($4));
    //    salvarTipoDeDados($1);
    }
}
| EXPRESSAO IGUAL ABRE_CHAVE LISTA_DE_PARAMETROS FECHA_CHAVE
| error '>' {;};

ATRIBUICAO: ID IGUAL VALOR_NUMERICO {
	if (!existeId($1)) {
		erroIdentificadorInexistente($1);
	} else {
		char *tipoEsperado = obterTipoDeDados($1);
		if(strcmp(tipoEsperado, "number") != 0) {
			erroAtribuicao(tipoEsperado, "number");
		} else {
    		atualizarValor($1, floatToAscii($3)); 
		}
	}
}
| ID IGUAL VALOR_TEXTUAL {
	if (!existeId($1)) {
		erroIdentificadorInexistente($1);
	} else {
		char *tipoEsperado = obterTipoDeDados($1);
		if (strcmp(tipoEsperado, "text") != 0) {
			erroAtribuicao(tipoEsperado, "text");
		} else {
    		atualizarValor($1, $3);
		}
	}
}
| ID IGUAL EXPRESSAO_NUMERICA {
	if (!existeId($1)) {
		erroIdentificadorInexistente($1);
	} else {
		char *tipoEsperado = obterTipoDeDados($1);
		if (strcmp(tipoEsperado, "number") != 0) {
			erroAtribuicao(tipoEsperado, "number");
		} else {
    		atualizarValor($1, floatToAscii($3));
		} 
	}
}
| ID IGUAL ID {
	if (!existeId($1)) {
		erroIdentificadorInexistente($1);
	} else if (!existeId($3)) {
		erroIdentificadorInexistente($3);
	} else { 
		char *tipoEsperado = obterTipoDeDados($1); 
		char *tipoFornecido = obterTipoDeDados($3); 
		if (strcmp(tipoEsperado, tipoFornecido) != 0) {
			erroAtribuicao(tipoEsperado, tipoFornecido);
		} else {
    		atualizarValor($1, obterValor($3));
		}
	}
};

FUNCOES_RESERVADAS: CLAUSULA_IF
| CLAUSULA_IF ELSE CLAUSULA_IF
| CLAUSULA_IF ELSE ABRE_CHAVE LINHA FECHA_CHAVE
| FOR ABRE_PARENTESES LISTA_VARS PONTO_VIRGULA OP_LOGICA PONTO_VIRGULA ID INC_DEC FECHA_PARENTESES ABRE_CHAVE LINHA FECHA_CHAVE
| WHILE ABRE_PARENTESES OP_LOGICA FECHA_PARENTESES ABRE_CHAVE LINHA FECHA_CHAVE;

CLAUSULA_IF: IF ABRE_PARENTESES OP_LOGICA FECHA_PARENTESES ABRE_CHAVE LINHA FECHA_CHAVE;

LISTA_VARS: EXPRESSAO
| ATRIBUICAO
| LISTA_VARS VIRGULA EXPRESSAO
| LISTA_VARS VIRGULA ATRIBUICAO;

TOKENS: ID { $$ = obterValor($1); }
| VALOR_NUMERICO { $$ = floatToAscii($1); }
| EXPRESSAO_NUMERICA { $$ = floatToAscii($1); }
| VALOR_TEXTUAL { $$ = $1; };

OP_LOGICA: TOKENS IGUAL_IGUAL TOKENS
| TOKENS DIFERENTE TOKENS 
| TOKENS MAIOR TOKENS 
| TOKENS MENOR TOKENS 
| TOKENS MAIOR_IGUAL TOKENS 
| TOKENS MENOR_IGUAL TOKENS
| ABRE_PARENTESES OP_LOGICA FECHA_PARENTESES IGUAL_IGUAL ABRE_PARENTESES OP_LOGICA FECHA_PARENTESES
| ABRE_PARENTESES OP_LOGICA FECHA_PARENTESES DIFERENTE ABRE_PARENTESES OP_LOGICA FECHA_PARENTESES
| ABRE_PARENTESES OP_LOGICA FECHA_PARENTESES AND ABRE_PARENTESES OP_LOGICA FECHA_PARENTESES
| ABRE_PARENTESES OP_LOGICA FECHA_PARENTESES OR ABRE_PARENTESES OP_LOGICA FECHA_PARENTESES;

EXPRESSAO_NUMERICA: VALOR_NUMERICO SOMA VALOR_NUMERICO { $$ = $1 + $3; }
| VALOR_NUMERICO SUBTRACAO VALOR_NUMERICO { $$ = $1 - $3; }
| VALOR_NUMERICO DIVISAO VALOR_NUMERICO { $$ = $1 / $3; }
| VALOR_NUMERICO MULTIPLICACAO VALOR_NUMERICO { $$ = $1 * $3; };

VALOR: VALOR_NUMERICO {
    if(!atribucaoValida("number")) {
        erroAtribuicao("number", floatToAscii($1));
    }
}
| VALOR_TEXTUAL {
    if(!atribucaoValida("text")) {
        erroAtribuicao("text", $1);
    }
};

LISTA_DE_PARAMETROS: ID
| VALOR
| LISTA_DE_PARAMETROS VIRGULA VALOR
| VALOR IGUAL VALOR { yyerror("Erro: atribuindo um valor a outro"); }
| error '>' {};

FUNCAO_DECLARACAO: TIPO_DE_DADOS ID ABRE_PARENTESES LISTA_DE_TIPOS_DE_DADOS FECHA_PARENTESES {
    if(!existeId($2)) {
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