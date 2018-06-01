%{
#include <stdio.h>
#include <stdlib.h>
int ac=0;
int bc=0;
%}

%token A B

%%
input: S "\n" { printf("Valid string\n"); exit(0); }
S: A S1 B | B { ++ac; ++bc; } 
S1: A S1 { ++ac; }
S1: ;

%%

void yyerror()
{
	printf("Error\n");
	exit(0);
	
}

int main()
{
	printf("Enter a string:\n");
	yyparse();
	exit(0);
}
