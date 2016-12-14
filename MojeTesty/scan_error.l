%{
#include <stdio.h>
#include <stdlib.h>

int yywrap(void);
int yylex(void);
void yyerror(const char *s);
%}

%x JEST

%%
"Blad"		ECHO; BEGIN(JEST);

<JEST>.		ECHO;
<JEST>\n	ECHO;
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
