#include<iostream>
using namespace std;

int capturedEnemyForts(int *arr,int size) {
	bool emptyFort=false;
	bool fort = false;
	bool enemyFort = false;
	for (int i = 0; i < size; i++) {
		if (arr[i] == 0) {
			enemyFort = true;
		}
		if (arr[i] == 1) {
			fort = true;
		}
		if (arr[i] == -1) {
			emptyFort = i;
		}
	}

	if (enemyFort && fort && emptyFort) {

		if (emptyFort == -1) {
			return 0;
		}

		int maximum = 0;
		int current = 0;
		bool found = false;
		for (int i = 0; i < size; i++) {
			if (arr[i] == -1 || arr[i] == 1) {
				found = true;
			}

			if (arr[i] == 0 && found) {
				maximum++;
			}
			else {
				maximum = 0;
			}

				current = max(current, maximum);
		}

		return current;
	}
	return 0;
	
}

int main() {

	int arr[] = {1,-1,-1,1};
	cout << capturedEnemyForts(arr, 9) << endl;

}