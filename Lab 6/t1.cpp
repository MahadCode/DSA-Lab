#include <iostream>
#include <vector>
#include "s.cpp"
using namespace std;

void nextSmallerLeft(vector<int> &orig, vector<int> &ans)
{
  Stack<int> s;
  s.push(0);
  ans[0] = -1;

  for (int i = 1; i < orig.size(); i++)
  {
    int current = orig[i];
    while (!s.empty() && current <= orig[s.top()])
    {
      s.pop();
    }
    if (s.empty())
    {
      ans[i] = -1;
    }
    else
    {
      ans[i] = s.top();
    }
    s.push(i);
  }
}

void nextSmallerRight(vector<int> &orig, vector<int> &ans)
{
  Stack<int> s;
  int size = orig.size();
  s.push(size - 1);
  ans[size - 1] = -1;

  for (int i = size - 2; i >= 0; i--)
  {
    int current = orig[i];
    while (!s.empty() && current <= orig[s.top()])
    {
      s.pop();
    }

    if (s.empty())
    {
      ans[i] = -1;
    }
    else
    {
      ans[i] = s.top();
    }

    s.push(i);
  }
}

int maximumAbsoluteDifference(vector<int> &arr)
{
  if (arr.size() == 0)
  {
    return 0;
  }
  vector<int> n1;
  vector<int> n2;
  vector<int> ans;
  for (int i = 0; i < arr.size(); i++)
  {
    ans.push_back(0);
    n1.push_back(0);
    n2.push_back(0);
  }

  nextSmallerLeft(arr, n1);
  nextSmallerRight(arr, n2);

  int maxDiff = INT_MIN;
  for (int i = 0; i < arr.size(); i++)
  {
    int leftSmaller = 0;
    int rightSmaller = 0;

    if (n1[i] != -1)
      leftSmaller = arr[n1[i]];

    if (n2[i] != -1)
      rightSmaller = arr[n2[i]];
      
    ans[i] = abs(leftSmaller - rightSmaller);
    maxDiff = max(maxDiff, ans[i]);
  }

  return maxDiff;
}

int main()
{
  vector<int> num = {1};
  cout << maximumAbsoluteDifference(num);
}