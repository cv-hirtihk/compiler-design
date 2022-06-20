%{
	#include <stdio.h>
	int flag = 0;
%}

%token NUMBER

%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
ArithmeticExpression: E {
			printf("\n\tResult = %d\n", $$);
			return 0;
						};

E:  E '+' E {$$ = $1 + $3;}
  | E '-' E {$$ = $1 - $3;}
  | E '*' E {$$ = $1 * $3;}
  | E '/' E {$$ = $1 / $3;}
  | E '%' E {$$ = $1 % $3;}
  | '('E')' {$$ = $2;}
  | NUMBER {$$ = $1;}
  ;
%%

void main()
{
	printf("\tEnter Arithmetic Expression: ");
	yyparse();
	if(flag == 0)
	{
		printf("\n\tEntered Arithmetic expression is Valid\n");
	}
}


void yyerror()
{
	printf("\n\tEntered Arithmetic expression is invalid\n");
	flag = 1;
}
