#include <bits/stdc++.h>
#include <climits>
using namespace std;

void merge(vector<int>& arr, int p, int q, int r) {
	vector<int> left, right;
	
	for (int i = p; i < q+1; i++) {
		left.push_back(arr[i]);
	}
	left.push_back(INT_MAX);
	for (int i = q+1; i <= r; i++) {
		right.push_back(arr[i]);
	}
	right.push_back(INT_MAX);

	int i = 0; int j = 0;
	for (int k = p; k <= r; k++) {
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		} else {
			arr[k] = right[j];
			j++;
		}
	}
}

void mergeSort(vector<int>& arr, int start, int end) {
	int q = ((start + end)/2);
	if (start < end) {
		mergeSort(arr, start, q);
		mergeSort(arr, q+1, end);
	}
	merge(arr, start, q, end);
}

void bubbleSort(vector<int>& arr) {
	for (int i = 0; i < arr.size()-1; i++) {
		bool flag = false;
		for (int j = i+1; j < arr.size(); j++) {
			if (arr[j] < arr[i]) {
				swap(arr[i], arr[j]);
				flag = true;
			}
		}
		if (!flag) {
			break;
		}
	}
}

int main(void) {
	vector<int> arr = {5,4,3,2,1};
	mergeSort(arr,0,4);
	for (auto num: arr) {
		cout << num << " ";
	}
	cout << endl;
	return 0;
}
