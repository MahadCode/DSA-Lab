#include<iostream>
using namespace std;

int* sumExceptSelf(int* nums, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += nums[i];
	}
	int* newArr = new int[size];
	for (int i = 0; i < size; i++) {
		newArr[i] = sum - nums[i];
	}

	return newArr;
}



int main() {
	int size = 4;
	int arr[] = { 1,2,3,4 };

	int* arr1 = sumExceptSelf(arr, size);
	for (int i = 0; i < size; i++) {
		cout << arr1[i] << endl;
	}
}