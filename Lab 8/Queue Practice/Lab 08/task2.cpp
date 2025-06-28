#include"Queuee.h"
using namespace std;

int circularTour(int petrol[], int distance[], int n){
    int start=0; int total_petrol=0; int current_balance=0;
    for(int i=0; i<n; i++){
        int net_petrol=petrol[i]-distance[i];
        total_petrol += net_petrol;
        current_balance += net_petrol;

        if(current_balance<0){
            start=i+1;
            current_balance=0;
        }
    }
    return (total_petrol>=0)? start: -1;
}

int main(){
    int petrol[] = {4, 6, 7, 4};
    int distance[] = {6, 5, 3, 5};
    int n = sizeof(petrol) / sizeof(petrol[0]);

    int startIndex = circularTour(petrol, distance, n);
    cout << "Start at petrol pump: " << startIndex << endl;

    return 0;
}

/*#include <iostream>
#include <queue>
using namespace std;

struct PetrolPump {
    int petrol;
    int distance;
};

// Function to find the starting pump
int findStartingPump(PetrolPump pumps[], int n) {
    queue<int> q;
    int current_petrol = 0, total_petrol = 0, start = 0;

    // Loop through all petrol pumps
    for (int i = 0; i < n; i++) {
        int net_petrol = pumps[i].petrol - pumps[i].distance;
        total_petrol += net_petrol;
        current_petrol += net_petrol;
        q.push(i);

        // If at any point, current_petrol goes negative, remove from queue
        while (current_petrol < 0 && !q.empty()) {
            start = q.front() + 1;  // Move to next pump
            current_petrol -= pumps[q.front()].petrol - pumps[q.front()].distance;
            q.pop();
        }
    }

    return (total_petrol >= 0) ? start : -1;  // If total petrol < 0, return -1
}

int main() {
    PetrolPump pumps[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
    int n = sizeof(pumps) / sizeof(pumps[0]);

    int start = findStartingPump(pumps, n);
    if (start != -1)
        cout << "Start at pump: " << start << endl;
    else
        cout << "No solution exists." << endl;

    return 0;
}
*/