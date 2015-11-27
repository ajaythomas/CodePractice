//queue using linked list

#include<iostream>

using namespace std;

class node
{
public:

    node()
    {
        info = 0;
        next = NULL;
    }

    node(int x)
    {
        info = x;
        next = NULL;

    }

    node(int x, node* m)
    {
        info = x;
        next = m;

    }

    void setNext(node* n)
    {
        this->next = n;
    }

    void resetNext()
    {
        this->next = NULL;
    }

    node* getNext()
    {
        return this->next;
    }

    int getInfo()
    {
        return this->info;
    }

private:
    int info;
    node* next;
};


class Queue
{
private:

    node *beg, *rear;

public:

    Queue()
    {
        beg = NULL;
        rear = NULL;

    }

    void enqueue(int x)
    {
        node *n = new node(x);
        if(beg == NULL)
        {
            beg = n;
            rear = n;
        }
        else
        {
            rear->setNext(n);
            rear = n;
        }
    }

    int dequeue()
    {
        if(beg == NULL)
            return -1;

        node* del = beg;
        int x = del->getInfo();
        beg = beg->getNext();
        delete del;
        return x;
    }

    void display()
    {
        node* i;
        if(beg == NULL)
        {
            cout<<"Queue empty";
        }

        for (i = beg; i != NULL ; i = i->getNext())
            cout<<i->getInfo()<<" ";
    }
};

int main()
{
    int choice, x;
    Queue *q = new Queue();
    do
    {
      cout<<"1 to enqueue, 2 to dequeue, 3 to display, 4 to exit"<<endl;
      cin>>choice;
      switch(choice)
      {
        case 1:
        cin>>x;
        q->enqueue(x);
        //beg = n;
        //enqueue(n, beg, rear);
        //cout<<beg->getInfo();
        break;

        case 2:
        cout<<q->dequeue()<<endl;
        //x = dequeue(beg,rear);
        break;

        case 3:
        q->display();
        break;

        case 4:
        return 0;


      }
    }
    while(true);

}
