#include<stdio.h>

int main()
{
    char c[100];
    scanf("%s",c);
    
    int i,n=0;
    for(int i=0;c[i]!='\0';i++)
        n++;

    char op1,op2,op3,op4,opr1,opr2;
    switch(n)
    {
        case 5:
            i=0;
            op1 = c[i];
            op2 = c[i+2];
            op3 = c[i+4];
            opr1 = c[i+3];
            printf("MOV %c,R0\n",op2);
            printf("MOV %c,R1\n",op3);
            if(opr1=='+')
                printf("ADD R0,R1\n");
            else if(opr1=='-')
                printf("SUB R0,R1\n");
            else if(opr1=='*')
                printf("MUL R0,R1\n");
            else if(opr1=='/')
                printf("DIV R0,R1\n");
            printf("MOV %c,R1\n",op1);
            break;
        case 7:
            i=0;
            op1 = c[i];
            op2 = c[i+2];
            op3 = c[i+4];
            op4 = c[i+6];
            opr1 = c[i+3];
            opr2 = c[i+5];
            printf("MOV %c,R0\n",op2);
            printf("MOV %c,R1\n",op3);
            if(opr1=='+')
                printf("ADD R0,R1\n");
            else if(opr1=='-')
                printf("SUB R0,R1\n");
            else if(opr1=='*')
                printf("MUL R0,R1\n");
            else if(opr1=='/')
                printf("DIV R0,R1\n");
            printf("MOV %c,R2\n",op4);
            if(opr2=='+')
                printf("ADD R1,R2\n");
            else if(opr2=='-')
                printf("SUB R1,R2\n");
            else if(opr2=='*')
                printf("MUL R1,R2\n");
            else if(opr2=='/')
                printf("DIV R1,R2\n");
            printf("MOV R2,%c\n",op1);
            break;
    }
    return 0;
}
