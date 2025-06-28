#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

string removeDuplicateLetters(string s)
{
    int freq[26] = {0};
    bool taken[26] = {false};
    stack<char> st;

    for (char c : s)
    {
        freq[c - 'a']++;
    }

    for (char c : s)
    {
        freq[c - 'a']--;
        if (taken[c - 'a'])
        {
            continue;
        }

        while (!st.empty() && st.top() > c && freq[st.top() - 'a'] > 0)
        {
            taken[st.top() - 'a'] = false;
            st.pop();
        }
        st.push(c);
        taken[c - 'a'] = true;
    }

    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    reverse(res.begin(), res.end()); 
    return res; 
}

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;
    
    string ans = removeDuplicateLetters(s);
    cout << "Lexicographically smallest string: " << ans << endl;

    return 0;
}
