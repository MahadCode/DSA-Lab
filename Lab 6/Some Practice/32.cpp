#include <iostream>
using namespace std;
#include <stack>
int longestValidParentheses(string s)
{
    stack<char> st;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='(')
        {
            st.push(s[i]);
        }

       else if (!st.empty() && s[i] == ')' && st.top() == '(')
        {
            count += 2;
            st.pop();
        }
    }
    return count;
}
int main()
{
    string s;
    cout << "Enter paranthesis: ";
    cin >> s;
    int ans = longestValidParentheses(s);
    cout << ans;
}