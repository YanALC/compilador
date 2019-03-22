%{
    #include <string.h>
    #include <stdlib.h>
    #include "../yacc/compilador.tab.h"
    void extern yyerror(char *);
    void TokenInvalido();
%}

espaco			[ \s\t\r\v\f]
quebraDeLinha	\n

%%
void	|
number	|
text	{
	yylval.tipoDeDados = strdup(yytext);
	return TIPO_DE_DADOS;
}

"+"				{ return SOMA; }
"-"				{ return SUBTRACAO; }
"/"				{ return DIVISAO; }
"*"				{ return MULTIPLICACAO; }
"," 			{ return VIRGULA; }
";"				{ return PONTO_VIRGULA; }
"="				{ return IGUAL; }
"("				{ return ABRE_PARENTESES; }
")"				{ return FECHA_PARENTESES; }
"{"				{ return ABRE_CHAVE; }
"}"				{ return FECHA_CHAVE; }
"["				{ return ABRE_COLCHETE; }
"]"				{ return FECHA_COLCHETE; }

"if"			{ return IF; }
"else"			{ return ELSE; }
"for"			{ return FOR; }
"while"			{ return WHILE; }
"print" 		{ return PRINT; }
"exit"			{ return SAIR; }

[-+]?[0-9]*\.?[0-9]+	{
	yylval.numVal = atof(yytext); 
	return VALOR_NUMERICO;
}

\"(\\.|[^"])*\"			{
	yylval.txtVal = strdup(yytext); 
	return VALOR_TEXTUAL;
}

[a-zA-Z][_a-zA-Z0-9]*	{
	yylval.tipoDeDados = strdup(yytext); 
	return ID;
}

{quebraDeLinha}			{ yylineno++; }
{espaco}				;
.						{ TokenInvalido(); }

%%

int yywrap(void){
    return 1;
}

void yyerror(char *msg) {
    fprintf(stderr, "\nErro na linha %d : \n %s\n", yylineno, msg);
    exit(0);
}

void TokenInvalido(){
    printf("Erro na linha %d : \n Token Invalido %s\n", yylineno, yytext);
    exit(0);
}