%{
	int id=0,op=0,v=0;
%}

%%
[a-zA-Z0-9]+	{ id++; printf("\nIdentifier: "); ECHO; }
[\+\-\*\/\=]	{ op++; printf("\nOperator:"); ECHO; }
"("	v++;
")"	v--;
.|\n	;
%%

int main()
{
	printf("\nEnter the expression\n");
	yylex();
	printf("\nCount of identifiers=%d and operators= %d ",id,op);
	if((op+1)==id && v==0)
		printf("Expression is Valid\n");
	else
		printf("\nExpression is invalid\n");
	return 0;
}
