#include<iostream>
using namespace std;

int main() {
	int n = 3;
	int arr[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	int r;
	cout << "Enter required" << endl;
	cin >> r;

	int found = false;

	for (int i = 0; i < 9; i++) {
		if (arr[i / 3][i % 3] == r) {
			found = true;
			break;
		}
	}

	cout << found << endl;
}