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

int getKWithModify(int a[], int beg, int end, int k)
{
	//THIS FUnction will modify array
	int x;
	x = partition(a,beg,end);
	if(k-1 == x)
		return a[x];
	else if(k-1 < x)
		getKWithModify(a, beg, x-1, k);
	else //(k-1 > x)
		getKWithModify(a, x + 1, end, k);
			
}

int getKWithoutModify(int a[], int beg, int end, int k)
{
	//cout<<"Beg is "<<beg<<" End is "<<end<<" k is "<<k<<endl;
	
	//THIS FUnction will use extra space
	int x = a[end];
	//cout<<"x is "<<x<<endl;
	
	if(beg == end)
	{
		//cout<<"beg = end"<<endl;
		return x;
		
	}
	
	if(beg == end - 1)
	{
		//cout<<"Beg = end - 1"<<endl;
		
		if(k == beg + 1)
		{
			//cout<<"k = beg + 1"<<endl;
			return a[beg];
			
		}
		else
			return x;
	}
	
	int a1[MAX], a2[MAX];
	int count1 = 0, count2 = 0;
	for(int i = beg; i < end; i++)
	{
		if(a[i] < x)
		{
			a1[count1++] = a[i];
		}
		else
			a2[count2++] = a[i];
		
	}
	
	/*cout<<"Count1 is "<<count1<<endl;
	cout<<"Count2 is "<<count2<<endl;*/
	
	if(count1 >= k)
		getKWithoutModify(a1, 0, count1 - 1, k);
	else if(k == count1 + 1)
		return x;
	else
		getKWithoutModify(a2, 0, count2 - 1, k - (count1 + 1));
}



int main(int argc, char **argv)
{
	int a[MAX], i, n, k;
	cout<<"Enter size of array (should be less than 100) "<<endl;
	cin>>n;
	cout<<"Enter elements"<<endl;
	for (i = 0; i < n ; i++)
	{
		cin>>a[i];
	}
	
	cout<<"Enter k as in kth smallest element. Enter 1 for smallest and so on"<<endl;
	cin>>k;
	
	if(k > n)
		return 0;
	
	int key;
	key = getKWithoutModify(a, 0, n-1, k);
	
	cout<<"Without modifying array, Kth smallest element is "<<key<<endl;
	
	key = getKWithModify(a, 0, n-1, k);
	
	cout<<"Modifying array, Kth smallest element is "<<key<<endl;
}