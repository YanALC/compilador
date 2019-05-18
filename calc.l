%{
#include <string.h>
#include <stdlib.h>
#include "calc.tab.h"
void extern yyerror(const char *);
int yylex();
void invalidToken();
%}

%%
"print"				   	{return PRINT;}
"exit"				   	{return EXIT;}
[a-zA-Z][a-zA-Z0-9]*	{yylval.id = strdup(yytext); return ID;}
[0-9]+(\.[0-9]+)?       {yylval.num = atof(yytext); return NUMBER;}
[ \s\t]					{;}
\n               		{yylineno++;}
"("						{return OPEN_PARENTHESIS;}
")"						{return CLOSE_PARENTHESIS;}
"-"						{return MINUS;}
"+"						{return PLUS;}
"="						{return EQUAL;}
"*"						{return MUL;}
"/"						{return DIV;}
"%"						{return MOD;}
"^"						{return POW;}
";"           	   		{return SEMICOLON;}
.                      	{invalidToken();}
%%

int yywrap (void) {return 1;}

void yyerror(const char *msg) {
    fprintf(stderr, "\nError in line %d : \n %s\n", yylineno, msg);
}

void invalidToken(){
    printf("Error in line %d : \n invalid token %s\n", yylineno, yytext);
    exit(0);
}