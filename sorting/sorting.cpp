/*
 * sorting.cpp
 *
 *  Created on: Mar 11, 2017
 *      Author: abhishek
 */



#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;


void insertion_sort(vector<int> &vec)
{
	int length = vec.size();
	for(int i=0; i< length -1 ; i++)
	{
		auto j  = i+1;
		auto k = i;

		while(vec[k] >  vec[j] && j>0)
		{
			swap(vec[k], vec[j]);
			j--;
			k--;
		}
	}
}

void bubble_sort(vector<int> &a)
{
	int size = a.size();
	for(int i=0; i< size ;i++)
	{
		for(int j=0; j< size - i -1; j++)
		{
			if(a[j] > a[j+1])
				swap(a[j], a[j+1]);
		}
	}
}

void selection_sort(vector<int> &a)
{
	int size = a.size();
	for(int i = 0 ; i < size;i++)
	{
		for(auto j = i+1 ;j < size; j++)
		{
			if(a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}

int main()
{
	vector<int> vec = {9,1,10,3,15,13,2,56,5,4};
	void (*myfunc)(vector<int>&);
	myfunc = insertion_sort;
	myfunc(vec);

	cout << "After insertion sort:";
	for(auto &i:vec)
		cout << i <<" ";
	cout << endl;

	random_shuffle(vec.begin(), vec.end());

	cout << "After random shuffle:";

	for(auto &i:vec)
		cout << i <<" ";
	cout << endl;
	myfunc = bubble_sort;

	myfunc(vec);
	cout << "After bubble sort:";
	for(auto &i:vec)
		cout << i <<" ";
	cout << endl;


	random_shuffle(vec.begin(), vec.end());

	cout << "After random shuffle:";

	for(auto &i:vec)
		cout << i <<" ";
	cout << endl;
	myfunc = selection_sort;

	myfunc(vec);
	cout << "After selection sort:";
	for(auto &i:vec)
		cout << i <<" ";
	cout << endl;
}



