#include <iostream>
#include <stack>

using namespace std;

string removeDigits(string s) {
    stack<char> st;

    for (char c : s) {
        if (isdigit(c)) {
            if (!st.empty()) st.pop();
        } else {
            st.push(c); 
        }
    }

    // Construct the final string from the stack
    string result;
    while (!st.empty()) {
        result = st.top() + result; // Build from back to front
        st.pop();
    }
    
    return result;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << "Resulting string: " << removeDigits(s) << endl;
    return 0;
}
