//palindrome string without extra storage

#include <iostream>

using namespace std;

bool IsPalindrome(char* str, int len)
{
    int i = 0;
    while(i < len/2)
    {
        //cout<<str[i]<<" "<<str[len -i]<<endl;
        if(str[i] != str[len - i - 1])
            return false;

        i++;
    }
    return true;
}

int main()
{
    int len, i;
    cout<<"Enter size of string"<<endl;
    cin>>len;
    char *str = new char[len]();
    for (i =0; i < len; i++)
        cin>>str[i];

    bool palin = IsPalindrome(str, len);

    if(palin)
        cout<<str<<" is a palindrome"<<endl;
    else
        cout<<str<<" is not a palindrome"<<endl;

}
