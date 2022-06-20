%{
	#include<stdio.h>
	#include<string.h>
	int i = 0;
%}

%%

([a-zA-Z0-9])* {i++;}

"\n" {printf("\t%d\n\t",i); i = 0;}

%%

int yywrap(void){}

int main()
{
	printf("\tEnter input: ");
	yylex();
	return 0;
}
