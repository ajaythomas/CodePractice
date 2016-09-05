#include <stdio.h>
#include<iostream>

#define MAX 100
using namespace std;

void swap(int a[], int m, int n)
{
	int temp = a[m];
	a[m] = a[n];
	a[n] = temp;	
}


int partition(int a[], int beg, int end)
{
	int x = a[end];
	
	int p = beg -1;
	
	for(int i = beg; i < end; i++)
	{
		if(a[i] < x)
		{
			p++;
			swap(a, i, p);		
		}
		
	}
	
	swap(a, (p + 1), end);
	
	return (p + 1);
	
}

void quickSort(int a[], int beg, int end)
{
	if(beg < end)
	{
		int x = partition(a,beg,end);
		quickSort(a,beg,x-1);
		quickSort(a,x+1, end);
	}
}



int main(int argc, char **argv)
{
	int a[MAX], i, n;
	cout<<"Enter size of array ( should be less than 100) "<<endl;
	cin>>n;
	cout<<"Enter elements"<<endl;
	for (i = 0; i < n ; i++)
	{
		cin>>a[i];
	}
	
	quickSort(a, 0, n - 1);
	
	for(i = 0; i < n; i++)
		cout<<a[i]<<" ";
}
