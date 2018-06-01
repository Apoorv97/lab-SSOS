#include<stdio.h>
#include<string.h>

char st[50];
char a[];
int len;
int i=0;
int top=-1;
void check(){
	int j=top;

	if(st[j]=='T' && st[j-1]=='+' && st[j-2]=='E'){
		if(a[i+1]=='*'){
			printf("%s\t%s\tDO NOT REDUCE E + T to E\n",st,a);
			return;
		}else{
			st[j]=' ';
			st[j-1]=' ';
			top=top-2;
			j=top;
			printf("%s\t%s\tREDUCE E + T to E\n",st,a);
			check();
		}
	}

	if(st[j]=='T'){
		st[j]='E';
		//st[j-1]='F';
		//top--;
		//j=top;
		printf("%s\t%s\tREDUCE T to E\n",st,a);
		check();
	}

	if(st[j]=='F' && st[j-1]=='*' && st[j-2]=='T'){
		st[j]=' ';
		st[j-1]=' ';
		top=top-2;
		j=top;
		printf("%s\t%s\tREDUCE T * F to T\n",st,a);
		check();
	}

	if(st[j]=='F'){
		st[j]='T';
		printf("%s\t%s\tREDUCE F to T\n",st,a);
		check();
	}

	if(st[j]==')' && st[j-1]=='E' && st[j-2]=='E'){
		st[j]=' ';
		st[j-1]=' ';
		st[j-2]='E';
		top=top-2;
		j=top;
		printf("%s\t%s\tREDUCE T * F to T\n",st,a);
		check();
	}



	if(st[j]=='d' && st[j-1]=='i'){
		st[j]=' ';
		st[j-1]='F';
		top--;
		j=top;
		printf("%s\t%s\tREDUCE id to F\n",st,a);
		check();
	}


	return;
}

void main(){
	printf("Enter the expression\n");
	gets(a);
	len=strlen(a);

	printf("STACK\tEXP\tACTION\n");

	for(i=0;i<len;i++){
		if(a[i]=='i' && a[i+1]=='d'){
			st[++top]='i';
			st[++top]='d';
			a[i]=' ';
			a[i+1]=' ';
			i++;
			printf("%s\t%s\tSHIFT\n",st,a);
			check();
			continue;
		}

		else{
			st[++top]=a[i];
			a[i]=' ';
			printf("%s\t%s\tSHIFT\n",st,a);
			check();
		}

	}

	return;
}	

