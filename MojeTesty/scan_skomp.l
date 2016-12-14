%{
#include <stdio.h>
#include <stdlib.h>

int yywrap(void);
int yylex(void);
void yyerror(const char *s);
%}

%x OUT

%%
>[[:BLANK:]]+	BEGIN(OUT);

<OUT>.		ECHO;
<OUT>\n		ECHO; BEGIN(INITIAL);
.
\n	
%%

int main(void)
{
	yylex();
	return 1;
}

int yywrap(void){
	return 1;
}
