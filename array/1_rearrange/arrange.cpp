/*
http://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers-publish/
Rearrange positive and negative numbers in O(n) time and O(1) extra space
*/

// A utility function to swap two elements
#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// A utility function to print an array
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%4d ", arr[i]);

	printf("\n");
}

// Even positive, Odd position negative
void rearrange(int arr[], int n)
{
	int p1 =0, p2 = n -1;
	while (p1 < p2) 
	{
		if ((p1 % 2 == 0)) {
		 while (arr[p1] < 0 && arr[p2] < 0 && (p1<p2))
		 	p2--;
		 if (arr[p2] > 0){
			swap(&arr[p1] , &arr[p2]);
			p1++;
			}
		} else {
		 while (arr[p1] > 0 && arr[p2] > 0 && (p1<p2))
		 	p2--;
		 if (arr[p2] < 0){
			swap(&arr[p1] , &arr[p2]);
			p1++;
		}
		}

	}
}

// Driver program to test above functions
int main()
{
	int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	rearrange(arr, n);
	printArray(arr, n);
	return 0;
}

