// This program dynamically creates 2D array.

#include <stdio.h>
#include <malloc.h>

int** create2D(int row, int col);


int main()
{
    int **p,i,j,r,c;
    r=5;
    c=5;
    p=create2D(r,c);
    if(p == NULL)
        return;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf(" %d",p[i][j]);
        }
        printf("\n");	
    }
    r=10;
    c=10;
    p = create2D(r,c);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf(" %d",p[i][j]);
        }
        printf("\n");	
    }


}

int** create2D(int row, int col)
{
    int i,j;

    // Allocate integer pointer equal to the number of rows. Each row contains a integer pointer
    int **p = (int**) malloc(row * sizeof(int *));

    if(p == NULL)
        return NULL;

    // Allocate integer memory equal to number of columns to row number of integer pointers previously allocated.
    for(i=0;i<row;i++)
        p[i]= (int*) malloc(col * sizeof(int));	

    if(p == NULL)
        return NULL;

    for(i=0;i<row;i++)
    {	
        for(j=0;j<col;j++)
        {
            p[i][j]=i+j;
        }
    }
    return p;
}
