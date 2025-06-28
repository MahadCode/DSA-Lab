#include <iostream>
#include <queue>
using namespace std;


void generateBinaryNumbers(int N) {
    queue<string> q; 
    q.push("1"); 

    for (int i = 1; i <= N; i++) {
        string current = q.front(); 
        q.pop(); 

        cout << current << " "; 
 
        q.push(current + "0");
        q.push(current + "1");
    }
}

int main() {
    int N = 5; 
    generateBinaryNumbers(N);
    return 0;
}
