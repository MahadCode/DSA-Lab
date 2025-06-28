#include <iostream>
#include <deque> 
using namespace std;

void slidingWindowMax(int arr[], int n, int k) {
    deque<int> q1;

    for (int i = 0; i < k; ++i) {
        while (!q1.empty() && arr[i] >= arr[q1.back()])
            q1.pop_back();
        q1.push_back(i);
    }

    for (int i = k; i < n; ++i) {
        cout << arr[q1.front()] << " ";

        while (!q1.empty() && q1.front() <= i - k)
            q1.pop_front();

        while (!q1.empty() && arr[i] >= arr[q1.back()])
            q1.pop_back();

        q1.push_back(i);
    }

    cout << arr[q1.front()] << endl;
}

int main() {
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int K = 3;
    int N = sizeof(arr) / sizeof(arr[0]);

    slidingWindowMax(arr, N, K);

    return 0;
}
