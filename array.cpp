#include <iostream>

using namespace std;

int main()
{
    int n,i;
    cin>>n;
    int *a = new int[n]();
    for(i =0; i < n;i++)
        cin>>a[i];
    for(i =0; i < n;i++)
        cout<<a[i]<<" ";
    delete a;


}
