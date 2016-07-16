//Counting Sort

#include<iostream>
using namespace std;

#define MAX 100

int main()
{
    int a[MAX],i,n, b[MAX], c[MAX];
    cin>>n;
    
    cout<<"Enter elements. Max should be smaller than 100"<<endl;
    
    for(i = 0; i < n;i++)
        cin>>a[i];
        
    int biggest = a[0];
        
    for(i = 1; i < n;i++)
        if(biggest < a[i])
            biggest = a[i];
    
    cout<<biggest<<endl;
    
    for(i=0;i <= biggest;i++)
        c[i] = 0;
        
    //c[i] contains count of elements in a that is equal to i
    for(i=0;i<n;i++)
        c[a[i]] = c[a[i]] + 1;
        
    //c[i] contains count of elements in a that is equal to or less than i
    for(i =1; i <= biggest; i++)
        c[i] = c[i-1] +c[i];
        
    cout<<"temp array contents"<<endl;
    for(i=0;i<=biggest;i++)
        cout<<c[i]<<" ";
        
    for(i = n-1; i >= 0;i--)
    {
        b[c[a[i]]-1] = a[i];
        c[a[i]] = c[a[i]] - 1;
        
    }
    
    cout<<"Count sort done"<<endl;
    cout<<"Sorted array"<<endl;
    
    for(i =0; i < n; i++)
        cout<<b[i]<<" ";
    
}