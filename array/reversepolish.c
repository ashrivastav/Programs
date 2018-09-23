#include<stdio.h>
#include<string.h>



void reversePolishNotation(char *p)
{

	char *temp;
	int length,i,top;
	char stack[400];
	length=strlen(p);
	temp=p;
	i=0;
	top=0;
	while(i<length)
	{
		if(*temp=='(' || *temp=='+' || *temp=='-' || *temp=='*' || *temp=='*' 
			|| *temp=='/' || *temp=='^')
		stack[top++]=*temp;
		
		else if(*temp >='a' && *temp<='z')
			printf("%c",*temp);
		else if(*temp == ')')
		{
			while(stack[--top]!='(' && top>=0)
				printf("%c",stack[top]);
		}	
		temp++;
		i++;
	}
	printf("\n");
}		

int main(){

	int total,i;
	char string[100][400];
	scanf("%d",&total);
	i=0;
	while(i < total && i <= 100)
	{	
		scanf("%s",string[i]);
		i++;
	}
	i=0;
	while(i <total)
		{
		reversePolishNotation(string[i]);	
		i++;
		}
	return 0;
}
