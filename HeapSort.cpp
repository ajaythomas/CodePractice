#include<iostream>

using namespace std;

#define MAX 100
int heapSize;

void maxHeapify(int a[], int i);
void buildMaxHeap(int a[]);
void heapSort(int a[], int n);

int main(int argc, char** argv)
{
	int n,a[MAX],i;
	cout<<"Enter size of array"<<endl;
	cin>>n;
	
	for(i = 0; i < n; i++)
		cin>>a[i];
		
	heapSize = n;
	
	heapSort(a,n);
	
	cout<<endl<<"Sorted Array"<<endl;
	for(i = 0; i <n; i++)
	    cout<<a[i]<<" ";
}

void heapSort(int a[], int n)
{
    int i;
    buildMaxHeap(a);
	
	cout<<"Heaped"<<endl;
    for(i = n-1; i > 0; i--)
    {
        swap(a[i],a[0]);
        heapSize--;
        maxHeapify(a,0);
    }
       
}

void buildMaxHeap(int a[])
{
    int i;
    for(i = heapSize/2 - 1; i >= 0; i--)
    {
        maxHeapify(a,i);
    }
    
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void maxHeapify(int a[], int i)
{
    int l,r,temp;
    l = 2*(i+1) - 1; //since indexing starts from 0 and not 1
    r = l + 1;
    
    int largest = i;
    
    if(l<heapSize && a[l] > a[largest])
        largest = l;
    
    if(r<heapSize && a[r] > a[largest])
        largest = r;
        
    if(largest != i)
    {
        swap(&a[largest],&a[i]);
        
        //temp = a[largest];
        //a[largest] = a[i];
        //a[i] = temp;
        
        maxHeapify(a,largest);
           
    }
}