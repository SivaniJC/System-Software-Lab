%{
    #include <stdio.h>
    #include <stdlib.h>
    int id=0,dig=0,key=0,op=0;
%}
%token DIGIT ID KEY OP
%%
input:
DIGIT input { dig++; }
| ID input { id++; }
| KEY input { key++; }
| OP input { op++; }
| DIGIT { dig++; }
| ID { id++; }
| KEY { key++; }
| OP { op++; }
;
%%

extern FILE *yyin;
int main()
{
    yyin=fopen ("demo.c","r");
    if(!yyin)
    {
        printf("File not found");
        exit(0);
    }
    yyparse();
    printf("Identifier count=%d, Digit count=%d,Keyword count=%d,Operator count=%d\n",id,dig,key,op);
    return 0;
}
void yyerror()
{
    printf("EEK,parse error! Message: ");
    exit(0);
}
