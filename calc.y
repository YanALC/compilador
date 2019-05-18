%{
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <sstream>
void yyerror(const char *msg);
int yylex();
extern char *yytext;

using namespace std;

unordered_map<string, float> ids;
%}

%union {char *id; float num;}
%start lines
%token PRINT EXIT
%token EQUAL PLUS MINUS MUL MOD DIV POW SEMICOLON OPEN_PARENTHESIS CLOSE_PARENTHESIS
%token <num> NUMBER
%token <id> ID
%type <num> exp term base factor
%type <id> assignment

%left PLUS MINUS
%left MUL DIV

%%
lines	: lines line SEMICOLON {;}
		|;

line    : assignment	{;}
		| EXIT 			{exit(EXIT_SUCCESS);}
		| PRINT exp 	{printf("%f\n", $2);};

assignment : ID EQUAL exp {ids[(string) $1] = $3;};

exp    	: term                  {$$ = $1;}
       	| exp PLUS term         {$$ = $1 + $3;}
       	| exp MINUS term        {$$ = $1 - $3;};

term   	: factor				{$$ = $1;}
		| term MUL factor		{$$ = $1 * $3;}
       	| term DIV factor		{$$ = $1 / $3;}
       	| term MOD factor		{$$ = fmod($1, $3);};

factor	: base POW base								{$$ = pow($1, $3);}
		| OPEN_PARENTHESIS exp CLOSE_PARENTHESIS	{$$ = $2;}
		| base										{$$ = $1;};

base   	: NUMBER                {$$ = $1;}
		| ID					{
			string var = (string) $1;
			if (ids.count(var) == 0) {
				stringstream ss;
				ss << "Variable " << var << " does not exists.";
				string msg = ss.str();
				yyerror(msg.c_str());
			} else {
				$$ = ids[var];
			}
		};
%%

int main (void) {
	return yyparse();
}

void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 

