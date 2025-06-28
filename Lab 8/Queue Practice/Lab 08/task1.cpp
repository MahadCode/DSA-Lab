#include "Queuee.h"
using namespace std;

void printFirstNegative(int arr[], int n, int k){
    Queuee<int> q1;

    for(int i=0; i<k; i++){
        if (arr[i] < 0)
            q1.enqueue(i);
    }

    for(int i=k; i<n; i++){
        if(!q1.isEmpty())
            cout << arr[q1.getFront()] << " ";
        else
            cout<<"0 ";
        while (!q1.isEmpty() && q1.getFront() <= i - k)
            q1.dequeue();
        if (arr[i] < 0)
            q1.enqueue(i);
    }

    if (!q1.isEmpty())
        cout << arr[q1.getFront()] << " ";
    else
        cout << "0 ";
}
int main(){
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int K = 3;
    int N = sizeof(arr) / sizeof(arr[0]);

    printFirstNegative(arr, N, K);

    return 0;
}