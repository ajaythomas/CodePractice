#include<iostream>

#define MAX 10

using namespace std;

int main()
{
    int i = 0, n, temp;
    cin>>n;
    
    int a[MAX];
    
    for(i = 0; i < n; i++)
    {
        cin>>a[i];    
    }
    
    for(i = 0; i < n/2; i++)
    {
        temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;    
    }
    
    for(i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";    
    }
}
