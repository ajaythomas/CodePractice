#include<iostream>

#define max 10

using namespace std;

class node
{
private:	
	int _info;
	node* _next;
	
public:
	node() { _info = 0; _next = NULL;}
	
	int GetInfo() { return _info;}
	node* GetNext() { return _next;}
	
	void SetInfo(int value) { this->_info = value;}
	void SetNext(node* ptr) { this->_next = ptr; }
	
};

class Stack
{
private:
	node* _top;
	
public:
	Stack() {_top = NULL;}
	
	void push(node* n) 
	{
		n->SetNext(_top);
		_top = n;
	}
	
	node* pop()
	{
		if(this->IsEmpty())
			return NULL;
		
		node* temp = _top;
		_top = _top->GetNext();
		return temp;
	}
	
	bool IsEmpty()
	{
		if(_top == NULL)
			return true;
		else
			return false;
	}
	
	void Display()
	{
		node* _top1 = this->_top;
		while(_top1 != NULL)
		{
			cout<<_top1->GetInfo()<<endl;
			_top1 = _top1->GetNext();
		}
	}
	
};

void insertAtBeg(Stack &s, node* temp)
{
	//inserts temp at the bottom of stack rather than top of stack
	
	if(s.IsEmpty())
	{
		s.push(temp);
	}
	else
	{
		node* element = s.pop();
		insertAtBeg(s, temp);
		s.push(element);
	}
}

void reverse(Stack &s)
{
	//recursive function
	//keep popping elements of the stack and hold it in the recursive function's call stack
	
	if(!s.IsEmpty())
	{
		node* temp = s.pop();
		reverse(s);
		insertAtBeg(s,temp);
	}
}

int main()
{
	int i, info;
	node* temp;
	Stack s;
	cout<<"Insert 10 elements in your stack"<<endl;
	for(i = 0; i < max; i++)
	{
		temp = new node();
		cin>>info;
		temp->SetInfo(info);
		s.push(temp);		
	}
	
	cout<<"Displaying All elements inserted"<<endl;
	
	s.Display();
	
	cout<<"Reversing stack and displaying"<<endl;
	
	reverse(s);
	
	s.Display();
}


