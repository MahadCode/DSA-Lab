#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isValid(string s)
{
    stack<char>st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        {
            st.push(s[i]);
        }
        else if((s[i]==')'&&st.top()=='(')||(s[i]=='}'&&st.top()=='{')||(s[i]==']'&&st.top()=='['))
        {
            st.pop();
        }
        else
        {
            return false;
        }
    }
    return st.empty();
}
int main()
{
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    bool a;
    a=isValid(s);
    cout<<a;
}