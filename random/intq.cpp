#include<iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;

int main(){

	char *a="hello";
	char *p = (char *)malloc(sizeof(100));
	p=a;
	printf(p);
	free(p);
}
