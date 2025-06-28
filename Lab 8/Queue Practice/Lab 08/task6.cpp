#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even!" << endl;
        return;
    }

    queue<int> firstHalf;
    int halfSize = n / 2;

    // Step 1: Move the first half of the queue to another queue
    for (int i = 0; i < halfSize; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // Step 2: Interleave firstHalf and remaining elements in the original queue
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    
    // Enqueue elements
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    
    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Call function to interleave queue
    interleaveQueue(q);

    // Print the modified queue
    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
