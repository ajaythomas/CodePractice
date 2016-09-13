#include <stdio.h>
#include<iostream>
#define MAX 100

using namespace std;

class BigInt
{
	
	//the digits of big int is stored in reverse order in array
	//so when printing, I print it from end of array to the 0th element
	//this should be considered when adding 2 BigInts together
	
private:
	int numbers[MAX];
	int IntCount;
	
public:
	BigInt()
	{
		for(int i = 0 ; i < MAX; i++)
			numbers[i] = 0;
			
		IntCount = 0;
	}
	
	BigInt(int a)
    {
        int count = 0;
        
        if(a == 0)
            BigInt();
        else
        {
			//initializing all elements to 0 first        
			for(int i = 0 ; i < MAX; i++)
				numbers[i] = 0;
			
            while(a != 0)
            {
                this->numbers[count] = a%10;
                a = a/10;
                count++;            
            }
            this->IntCount = count;
        }       
        
    }
	
	BigInt(const BigInt& a)
	{
		IntCount = a.IntCount;
		for(int i = 0; i < MAX; i++)
		{
			numbers[i] = a.numbers[i];		
		}
		
	}
	
	BigInt* operator+(const BigInt& a)
	{
		BigInt* ret;
		
		if(this->IntCount == 0)
			ret = new BigInt(a);
		else if(a.IntCount == 0)
			ret = new BigInt(*this);
		else
		{
			ret = new BigInt();
			int maxCount = this->IntCount > a.IntCount ? this->IntCount : a.IntCount;
			
			int m, count = 0, carry = 0;
			while(count < maxCount)
			{
				m = a.numbers[count] + this->numbers[count] + carry;
				//cout<<"M sum is "<<m<<endl;
				ret->numbers[count] = m%10;
				//cout<<ret->numbers[count]<<endl;
				carry = m/10;
				//cout<<"Carry is "<<carry<<endl;
				count++;				
			}
			
			ret->numbers[count] = carry;
			if(ret->numbers[count] != 0)
				ret->IntCount = count + 1;
			else
				ret->IntCount = count;
		}
		
		return ret;
	}
	
	
	friend ostream& operator<<(ostream& os, const BigInt& bi)
	{
		if(bi.IntCount == 0)
            os<<0;
            
        else
        {
            int count = bi.IntCount - 1;
            while(count >= 0)
            {
                os<<bi.numbers[count--];                
            }
            
        }
		
		return os;
		
	}
	
};



int main(int argc, char **argv)
{
	BigInt* a = new BigInt(7778);
	cout<<*a<<endl;
	BigInt* b = new BigInt(9888);
	cout<<*b<<endl;
	BigInt* c = *a + *b;
	cout<<*c<<endl;
	BigInt* d = new BigInt(*a);
	cout<<*d<<endl;
	
	delete a;
	delete b;
	delete c;
	delete d;
	
}
