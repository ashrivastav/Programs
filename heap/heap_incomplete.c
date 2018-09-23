/* HeapSort and priority queue as mentioned in Cormen, all functions that are needed are implemented here 
	after understanding each function use and its use in heapsort and priority queue
	Naming conventions is similar to book, for easy reference		*/

/* Five functions are used for implementing priortiy queue data structure and heapsort. They are :- 

1. MaxHeapify function, which runs in O(log n) time, is the key to maintaining the max-heap property.
2. BuildMaxHeap function, which runs in linear time, produces a maxheap from an unordered input array.
3. HeapSort function, which runs in O(n log n) time, sorts an array in-place.
4. The MaxHeapInsert, HeapExtractMax, HeapIncreaseKey and HeapMaximum functions , which run in O(log n) time
   allow the heap data structure to be used as a priority queue.
*/

#include <stdio.h>
#include <math.h>

#define SIZE 11
#define MAX_TREE_SIZE SIZE-1

// MaxHeapify adjust a node by comparing its children with parent and repeat this recursively till leaves
void MaxHeapify(int *a,int node);

// BuildMaxHeap create a heap from an unordered array, using MaxHeapify function
void BuildMaxHeap(int *a, int length);

void HeapSort(int *a);

int main()
{
	// Heap is a complete binary tree, therefore array is efficient as data structure for heapsort
	int a[SIZE],i;	
	
	for(i=0;i<SIZE;i++)
		a[i]= rand()%100;

	printf("\n Original array \n");
	for(i=0;i<SIZE;i++)
		printf(" %d ",a[i]);
	printf("\n");
	
	//BuildMaxHeap(a,MAX_TREE_SIZE);
	
	printf("\n After BuildMaxHeap \n");
	for(i=0;i<SIZE;i++)	
		printf(" %d-- ",a[i]);

	printf("\n");
	
}

// Basic function which heapify a node in a tree, passed to it.
void MaxHeapify(int *a, int node)
{	
	int left, right,largest,temp;
	
	left = 2*node +1;
	right= 2*node +2;
	
	if(node*2 > MAX_TREE_SIZE)
		return;

	largest = node;	
	if(left < SIZE && a[left] > a[node] && a[right] < a[left])
		{	
			largest=left;
		}
	
	else if (right < SIZE && a[right] > a[node] && a[left] < a[right])
		{
			largest=right;
		}	
	else if (right < SIZE && left < SIZE && a[node] > a[left] && a[node] > a[right] )
			{
				largest = node;
				return;
			}
	if(largest != node)
		{	temp = a[node];
			a[node] = a[largest];
			a[largest] = temp;
			MaxHeapify(a,largest);
		}
}

// Builds a Heap from unordered array and uses MaxHeapify for it
// Calls MaxHeapify 
void BuildMaxHeap(int *a, int range)
{
	int i;
	for( i=(range-1)/2;i>=0;i--)
		MaxHeapify(a,i);
}

/* Sorts using MaxHeapify and BuildMaxHeap, First creates Heap and then removes the root element and replace it with
the last element in the tree, and then call MaxHeapify on the root element */
void HeapSort(int *a)
{
	BuildMaxHeap(a,MAX_HEAP_SIZE);
	
