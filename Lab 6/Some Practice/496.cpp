#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums2.size();
    vector<int> vec(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums2[st.top()] <= nums2[i])
        {
            vec[st.top()] = nums2[i];
            st.pop();
        }

        st.push(i);
    }
    int n1 = nums1.size();
    vector<int> vec3(n1);
    for (int j = 0; j < n1; j++)
    {
        for (int k = 0; k < n; k++)
        {
            if (nums1[j] == nums2[k])
            {
                vec3[j] = vec[k];
            }
        }
    }
    return vec3;
}

int main()
{
    int size1;
    cout << "Enter the size of array 1: ";
    cin >> size1;

    vector<int> vec1(size1);
    cout << "Enter the elements of array 1:\n";
    for (int i = 0; i < size1; i++)
    {
        cin >> vec1[i];
    }
    int size2;
    cout << "Enter the size of array 1: ";
    cin >> size2;
    vector<int> vec2(size2);
    cout << "Enter the elements of array 1:\n";
    for (int i = 0; i < size2; i++)
    {
        cin >> vec2[i];
    }
    vector<int> nextGreater = nextGreaterElement(vec1, vec2);
    cout << "Next Greater Elements:\n";
    for (int num : nextGreater)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
