#include<stdio.h>
#include<stdlib.h>

int m,n,i,j,k=0,ch=0,flag,count=0,rev;
int inp[30],frame[30],idx[10],min;

void fifo();
void lru();
void getData();

void main()
{
	for(;;)
	{
		printf("Enter your choice\n1.FIFO\n2.LRU\n3.Exit\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:fifo();
				break;
			case 2:lru();
				break;
			case 3:exit(0);
		}
	}
}

void getData()
{
	printf("Enter the number of pages\n");
	scanf("%d",&n);
	printf("Enter the length of frames\n");
	scanf("%d",&m);
	printf("Enter the page sequence\n");
	for(i=0;i<n;i++)
	scanf("%d",&inp[i]);

	count=0;
	j=0;

	for(i=0;i<m;i++)
		frame[i]=-1;
}

void fifo()
{
	getData();
	printf("\nPAGE\tFRAME\tPage faults\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",inp[i]);
		flag=0;
		for(k=0;k<m;k++)
			if(frame[k]==inp[i])
				flag=1;
		if(flag==0)
		{
			frame[j]=inp[i];
			j=(j+1)%m;
			count++;
			for(k=0;k<m;k++)
			printf("%d ",frame[k]);
			printf("\tPage fault %d\n",count);
		}
		else
		{
			for(k=0;k<m;k++)
			printf("%d ",frame[k]);
			printf("\tNo page fault\n");
		}
	}
	printf("The total number of page fault is %d\n",count);
}

void lru()
{
	getData();
	printf("\nPAGE\tFRAME\tPage faults\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",inp[i]);
		flag=0;
		for(k=0;k<m;k++)
			if(frame[k]==inp[i])
				flag=1;
		if(flag==0)
		{
			for(k=0;k<m;k++)
			{
				rev=i-1;
				while(frame[k]!=inp[rev])
				rev--;
				idx[k]=rev;
			}
			min = 999;
			for(k=0;k<m;k++)
				if(min>idx[k])
					min=idx[k];

			while(frame[j]!=inp[min])
				j=(j+1)%m;
	
			frame[j]=inp[i];
			count++;

			
			for(k=0;k<m;k++)
			printf("%d ",frame[k]);
			printf("\tPage fault %d\n",count);
		}
		else
		{
			for(k=0;k<m;k++)
			printf("%d ",frame[k]);
			printf("\tNo page fault\n");
			
		}
	}
	printf("The total number of page fault is %d",count);
	
}
