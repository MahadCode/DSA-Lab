#include <iostream>
using namespace std;
#include <algorithm>
#include <stack>
#include <vector>
#include <string>
string clearStars(string s)
{
    int size = s.length();
        if (s.find('*') == string::npos)
    {
        return s;
    }
    sort(s.begin(), s.end());
    stack<char> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '*')
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            st.push(s[i]);
        }
    }
    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}
int main()
{
    string s, ans;
    cout << "Enter the string: ";
    cin >> s;
    ans = clearStars(s);
    cout << ans;
}