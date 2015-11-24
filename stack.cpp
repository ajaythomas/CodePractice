#include <iostream>
#define MAX 5

using namespace std;

void push(int *a, int m, int& top)
{
  if(top == MAX - 1)
    cout<<"Stack full"<<endl;
  else
    a[++top] = m;
}

int pop(int *a, int& top)
{
    if(top == -1)
    {
        cout<<"Stack empty";
        return -1;
    }
    else
    {
        int x = a[top];
        a[top--] = 0;
        return x;
    }
}

void display(int *a, int top)
{
    int i;
    if(top == -1)
    {
        cout<<"Stack empty";
    }

    for (i = top; i >= 0 ; i--)
        cout<<a[i]<<" ";
}

int main()
{
    int a[MAX],choice, top=-1, x;
    do
    {
      cout<<"1 to push, 2 to pop, 3 to display, 4 to exit"<<endl;
      cin>>choice;
      switch(choice)
      {
        case 1:
        cin>>x;
        push(a,x,top);
        break;

        case 2:
        x = pop(a,top);
        cout<<x<<endl;
        break;

        case 3:
        display(a,top);
        break;

        case 4:
        return 0;


      }
    }
    while(true);

}
