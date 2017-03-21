/*
 * index_sorting.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: abhishek
 */
#include <iostream>
#include<algorithm>
using namespace std;


void reorder(int arr[], int index[], int n)
{
	int i = 0;
	int count =0;

	while(i < n)
	{
		while(i != index[i])
		{
			swap(arr[i], arr[index[i]]);
			swap(index[i], index[index[i]]);
			count++;
		}
		i++;
		count++;
	}
	cout <<"total operation-->" << count <<"  n is " << n;
}


// Driver program
int main()
{
    int arr[] = {50, 40, 70, 60, 90};
    int index[] = {3,  0,  4,  1,  2};
    int n = sizeof(arr)/sizeof(arr[0]);

    reorder(arr, index, n);

    cout << "Reordered array is: \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";

    cout << "\nModified Index array is: \n";
    for (int i=0; i<n; i++)
        cout << index[i] << " ";
    return 0;
}

