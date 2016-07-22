#include<stdio.h>

int total;
int i;
int result[100];
int input[100][100];
int dynarr[100][100];
int row,col;
int max(int i, int j)
{
	return (i>j)?i:j;
}

int max2(int i, int j, int k)
{
	return (i>j)?((i>k)?i:k):((j>k)?j:k);
}

int findMax(){

	int r1=1,c1=0;
	int a=row-1,b=1,maxval;
	if(row>1 && col==1)
		{	
			maxval=0;
			r1=0;
			while(r1<row)
				{
					maxval += dynarr[r1][0];
					r1++;
				}
			return maxval;
		}
	if(col>1 && row==1)
		{
			maxval=dynarr[0][0];
		while(b < col)
			{
			if(maxval<dynarr[0][b])
				maxval=dynarr[a][b];
			b++;
			}
		return maxval;
		}
	if(row>1 && col>1)
	{
	
		while(r1<row && c1<col)
		{
		if(c1==0)
		{
			dynarr[r1][c1] += max(dynarr[r1-1][c1],dynarr[r1-1][c1+1]);
	//		printf("%d ", dynarr[r1][c1]);
			c1++;
		}
		else if(c1==col-1)
		{
			dynarr[r1][c1] += max(dynarr[r1-1][c1-1],dynarr[r1-1][c1]);
	//		printf("%d ", dynarr[r1][c1]);
			r1++;
			c1=0;

		}
		else
		{
		dynarr[r1][c1] += max2(dynarr[r1-1][c1-1],dynarr[r1-1][c1],dynarr[r1-1][c1+1]);
	//	printf("%d ", dynarr[r1][c1]);
		c1++;
		}
		}
	}
		maxval=dynarr[a][0];
		while(b < col)
			{
			if(maxval<dynarr[a][b])
				maxval=dynarr[a][b];
			b++;
			}
		return maxval;
}
int main()
{
	i=0;
	int r,c;
	int count;
	scanf("%d",&total);
		
	while(i < total)
	{
		scanf("%d  %d",&row,&col);
		count=row*col;
		r=0;
		c=0;
		while(count-- > 0)
		{
			scanf("%d",&input[r][c]);
			dynarr[r][c]=input[r][c];
			if(c<col-1)
			  c++;
			else
			 {
			    c=0;
			    r++;
			}
		}
		result[i]=findMax();
		i++;
	}
	i=0;
	while(i < total)
	{
		printf("%d\n",result[i]);
		i++;
	}
return 0;
}
