%{
#include <stdio.h>
#include <stdlib.h>

int yywrap(void);
int yylex(void);
void yyerror(const char *s);
%}

%x OUT

%%
OUTPUT\n	BEGIN(OUT);
<OUT>.
<OUT>\n

.		ECHO;
\n		ECHO;
%%

int main(void)
{
	yylex();
	return 1;
}

int yywrap(void){
	return 1;
}
