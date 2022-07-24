%{
	#include<stdio.h>
	#include<stdlib.h>
%}
%token A B
%%
input: S '\n' { printf("Successful Grammer\n"); exit(0); }
S: A M B | B
M: A M | ;
%%
int main()
{
	printf("Enter a string: ");
	yyparse();
}
int yyerror()
{
	printf("Error\n");
	exit(0);
}
