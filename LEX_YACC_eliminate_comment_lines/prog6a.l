%%
"//".*	;
"/*"[^*/]*"*/"	;
%%
int main()
{
	yyin=fopen("input.c","r");
	yyout=fopen("output.c","w");
	yylex();
}
