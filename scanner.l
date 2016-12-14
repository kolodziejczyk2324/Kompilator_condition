%{
#include <iostream>
#include "parser.tab.h"

using namespace std;
#define YY_DECL extern "C" int yylex()
%}

%option yylineno

%%

VAR		{ return VAR; }
"BEGIN"		{ return _BEGIN; }
END		{ return END; }
READ		{ return READ; }
WRITE		{ return WRITE; }
SKIP		{ return SKIP; }
IF		{ return IF; }
THEN		{ return THEN; }
ELSE		{ return ELSE; }
ENDIF		{ return ENDIF; }
"<>"		{ return NEQ; }
">="		{ return GOET; }
"<="		{ return LOET; }
">"		{ return GT; }
"<"		{ return LT; }
":="		{ return PRZYPISANIE; }
"="		{ return EQ; }
"+"		{ return PLUS; }
"-"		{ return MINUS; }
";"		{ return SREDNIK; }
"["		{ return LB; }
"]"		{ return RB; }

[0-9]+		{ yylval.ival = atoi(yytext); return NUMBER; }
[_a-zA-Z0-9]+	{ yylval.sval = strdup(yytext); return IDENTIFIER; }
[[:BLANK:]]+
\n	
%%

int yywrap(void){
	return 1;
}
