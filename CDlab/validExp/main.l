%{
#include<stdio.h>
int op=0,id=0;
%}

%%

[a-zA-Z]+[0-9a-zA-Z]* {id++;}
[+|-|*|/|=] {op++;}

%%

int main ()
{
	printf("\tEnter the expression: ");
	yylex();
	if((op+1) == id)
	{
		printf("\tThe entered expression is valid\n");
	}

	else 
	{
		printf("\tThe entered expression is not valid\n");
	}
}
