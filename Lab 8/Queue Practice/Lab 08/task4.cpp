#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeatingCharacter(string stream) {
    queue<char> q;       
    int freq[256] = {0};  

    for (char ch : stream) {
        freq[ch]++;  
        q.push(ch);  
        
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }
        
        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout << "# ";  
        }
    }
}

int main() {
    string input = "aabcdb";
    firstNonRepeatingCharacter(input);
    return 0;
}
