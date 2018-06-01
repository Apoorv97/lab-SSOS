%{
	#include<stdio.h>
	int a[2] = {0,0};
	int valid,i;
	int nop;

%}

%%
[0-9]+	{if(valid==0)
	 {
		valid = 1;
		nop++;
	 }
	 else 
		ext();
	}
"+"	{if(valid)
	 {
		valid = 0;
		i=0;
		a[i]++;
	 }
	 else
		ext();
	}
"*"	{if(valid)
	 {
		valid = 0;
		i=1;
		a[i]++;
	 }
	 else
		ext();
	}
. | \n	{ext();}

%%

int ext()
{
	printf("Invalid expression\n");
	exit(0);
}

int main()
{
	printf("Enter the expression\n");
	yylex();
	if(valid==1)
	{
		printf("Expression is valid");
		printf("\nThe number of + : %d\n",a[0]);
		printf("\nThe number of * : %d\n",a[1]);
		printf("\nThe number of operands : %d\n",nop);
		return 0;
	}
       	ext();
}
