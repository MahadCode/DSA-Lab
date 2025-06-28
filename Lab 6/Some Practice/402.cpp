#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <stack>
string removeKdigits(string num, int k)
{
    stack<char> st;
    for (int i = 0; i < num.length(); i++)
    {
        while (k > 0 && !st.empty() && st.top() > num[i])
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while(k>0 &&!st.empty())
    {
        st.pop();
        k--;
    }

    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    int i = 0;
    while (i < res.length() && res[i] == '0')
    {
        i++;
    }
    if (i == res.length())
        return "0";
    return res.substr(i);
}
int main()
{
    string s, ans;
    int k;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter the number of removal digits: ";
    cin >> k;
    ans = removeKdigits(s, k);
    cout << ans;
}