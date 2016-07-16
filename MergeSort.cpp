#include <iostream>
using namespace std;

#define MAX 100

void mergeSort(int a[], int beg, int end);
void merge(int a[], int beg, int mid, int end);

int main(int argc, char **argv)
{
	int n, beg = 0, end =0;
	int a[100];
	
	cout<<"Enter size of array to be sorted"<<endl;
	cin>>n;
	
	cout<<"Enter elements"<<endl;
	
	for(int i= 0; i < n; i++)
		cin>>a[i];
	
	end = n-1;
	
	mergeSort(a, beg,end);
	
	cout<<endl;
	
	for(int i= 0; i < n; i++)
		cout<<a[i]<<" ";
}

void mergeSort(int a[], int beg, int end)
{
	int mid;
	if(beg < end)
	{
		mid = (beg + end)/2;
		mergeSort(a, beg, mid);
		mergeSort(a, mid + 1, end);
		merge(a, beg, mid, end);
	
	}

}

void merge(int a[], int beg, int mid, int end)
{
	int size1 = mid - beg + 1;
	int size2 = end - mid;
	//int *b = new int[];
	int i,j,k;
	int b[MAX], c[MAX];
	
	for(i = 0; i < size1; i++)
		b[i] = a[beg + i];
		
	for (i = 0; i < size2; i++)
		c[i] = a[mid + 1 + i];
		
	i = 0;
	j = 0;
	k = beg;
	
	while(i < size1 && j < size2)
	{
		if(b[i] < c[j])
			a[k++] = b[i++];
		else if(b[i] > c[j])
			a[k++] = c[j++];
		else
		{
			a[k++] = b[i++];
			a[k++] = c[j++];			
		}	
	
	}
	
	if(i < size1)
	{
		while(i < size1)
		{
			a[k++] = b[i++];
		}	
	
	}
	
	if(j < size2)
	{
		while(j < size2)
		{
			a[k++] = c[j++];
		}
	}
	
}


