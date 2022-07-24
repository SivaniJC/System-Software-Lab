#include <stdio.h>
#include <string.h>

int k=0, z=0, i=0, j=0, c=0;
char a[16], ac[20], stk[15], act[10];

void check();

int main()
{
    printf("GRAMMER is:\nE->E+T|T\nT->T*F|F\nF->(E)|id\n");
    printf("Enter input string\n");
    scanf("%s", a);
    c = strlen(a);
    printf("stack \t input \t action\n");
    printf("------\t-------\t-------\n");
    printf("\n$%s\t%s$\t", stk, a);
    for (k=0, i=0; j<c; k++, i++, j++)
    {
        if (a[j]=='i' && a[j+1]=='d')
        {
            strcpy(act, "SHIFT ");
            stk[i] = a[j];
            stk[i+1] = a[j+1];
            stk[i+2] = '\0';
            a[j] = ' ';
            a[j+1] = ' ';
            printf("\n$%s\t%s$\t%sid", stk, a, act);
            check();
        }
        else if (a[j]=='+' || a[j]=='*')
        {
            strcpy(act, "SHIFT ");
            stk[i] = a[j];
            stk[i+1] = '\0';
            a[j] = ' ';
            printf("\n$%s\t%s$\t%s%c", stk, a, act, stk[i]);
            check();
        }
        else
        {
            printf("\nERROR IN INPUT\n");
            break;
        }
    }
    if (stk[0]=='E' && j==c)
        printf("\n****SUCESSFULL PARSING****\n");
    else
        printf("****FAILURE IN PARSING****\n");
}

void check()
{
    strcpy(ac, "REDUCE F->id");
    for (z=0; z<c; z++)
    {
        if(stk[z] == 'i' && stk[z+1]=='d')
        {
            stk[z] = 'F';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            j++;
        }
    }
    strcpy(ac, "REDUCE T->T*F");
    for (z=0; z<c; z++)
    {
        if(stk[z] == 'T' && stk[z+1]=='*' && stk[z+2] == 'F')
        {
            stk[z] = 'T';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i = i - 2;
        }
    }
    strcpy(ac, "REDUCE T->F");
    for (z=0; z<c; z++)
    {
        if(stk[z] == 'F')
        {
            stk[z] = 'T';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
        }
    }
    strcpy(ac, "REDUCE E->E+T");
    for (z=0; z<c; z++)
    {
        if (stk[z] == 'E' && stk[z+1] == '+' && stk[z+2] == 'T' && stk[z+3] != '*' && a[j+1] != '*')
        {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            stk[z + 3] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i = i - 2;
        }
        else if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'T' && j == c)
        {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i = i - 2;
        }
        else
        {
            break;
        }
    }
    strcpy(ac, "REDUCE E->T");
    for(z = 0; z < c; z++)
    {
        if(stk[z] == 'T')
        {
            if(a[j + 1] == '+' || a[j + 1] == '\0')
            {
                stk[z] = 'E';
                stk[z + 1] = '\0';
                printf("\n$%s\t%s$\t%s", stk, a, ac);
            }
            else
                break;
        }
    }
    strcpy(ac, "REDUCE F->(E)");
    for(z = 0; z < c; z++)
    {
        if(stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')')
        {
            stk[z] = 'F';
            stk[z + 1] = '\0';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i = i - 2;
        }
    }
}
