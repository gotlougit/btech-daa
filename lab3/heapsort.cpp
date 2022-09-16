#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int Parent(int i) {
	return floor(i-1/2);
}

int Left(int i) {
	return 2*i + 1;
}

int Right(int i) {
	return 2*i + 2;
}

void MaxHeapify(vector<int>& arr, int i, int heapsize) {
	int l = Left(i);
	int r = Right(i);
	int largest = i;
	if (l < heapsize &&	arr[l] > arr[i]) {
		largest = l;
	}
	if (r < heapsize && arr[r] > arr[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(arr[i], arr[largest]);
		MaxHeapify(arr, largest, heapsize);
	}
}

void BuildMaxHeap(vector<int>& arr, int l) {
	for (int i = l/2; i > -1; i--) {
		MaxHeapify(arr,i, arr.size());
	}
}

void HeapSort(vector<int>& arr) {
	int l = arr.size();
	BuildMaxHeap(arr, l);
	for (int i = arr.size()-1; i > 0; i--) {
		swap(arr[0], arr[i]);
		l--;
		MaxHeapify(arr,0, l);
	}
}

int main(void) {
	vector<int> arr;
	arr.push_back(5);
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(1);
	for (auto n: arr) {
		cout << n << " ";
	}
	cout << endl;
	HeapSort(arr);
	for (auto n: arr) {
		cout << n << " ";
	}
	cout << endl;
	return 0;
}
