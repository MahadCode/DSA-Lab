#include <iostream>
using namespace std;
#include <vector>
#include <stack>
vector<int> finalPrices(vector<int> &prices)
{
    stack<int> st;
    int n = prices.size();
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && prices[st.top()] >=prices[i])
        {
            vec[st.top()] = prices[i];
            st.pop();
        }
        st.push(i);
    }
    vector<int> vec3(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (vec[i] == 0)
        {
            vec3[i] = prices[i];
        }
        vec3[i] = prices[i] - vec[i];
    }
    return vec3;
}
int main()
{
    int size;
    cout << "Enter the size of vector: ";
    cin >> size;
    vector<int> vec(size);
    cout << "Enter the elements of vector\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Element number " << i + 1 << ": ";
        cin >> vec[i];
    }
    vector<int> vec1(size);
    vec1 = finalPrices(vec);
    for (int num : vec1)
    {
        cout << num << " ";
    }
}