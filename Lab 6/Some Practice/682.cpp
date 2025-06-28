#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cctype> 
using namespace std;
int calPoints(vector<string> &operations)
{
    stack<int> st; 
    for (const string &op : operations)
    {
        if (isdigit(op[0]) || (op.size() > 1 && isdigit(op[1]))) // Handles negative numbers too
        {
            st.push(stoi(op));
        }
        else if (op == "+")
        {
            if (st.size() >= 2)
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a); // Push back 'a' before adding new sum
                st.push(a + b);
            }
        }
        else if (op == "D")
        {
            if (!st.empty())
            {
                st.push(2 * st.top());
            }
        }
        else if (op == "C")
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
    }

    // Sum up stack values
    int sum = 0;
    while (!st.empty())
    {
        sum += st.top();
        st.pop();
    }

    return sum;
}

int main()
{
    int size;
    cout << "Enter the size: ";
    cin >> size;

    vector<string> vec(size);
    cout << "Enter the elements of vector: \n";
    for (int i = 0; i < size; i++)
    {
        cout << "Element number " << i + 1 << ": ";
        cin >> vec[i];
    }

    int ans = calPoints(vec);
    cout << "Final Score: " << ans << endl;

    return 0;
}
