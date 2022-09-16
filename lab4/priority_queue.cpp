#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int Parent(int i) {
	return floor((i-1)/2);
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

int Max(vector<int>& arr) {
	return arr[0];
}

int ExtractMax(vector<int>& arr) {
	if (arr.size() < 1) {
		return -1;
	}
	int m = Max(arr);
	int l = arr.size()-1;
	arr[0] = arr[l];
	arr.erase(arr.begin() + l);
	BuildMaxHeap(arr, l);
	return m;
}

void IncreaseKey(vector<int>& arr, int i, int key) {
	if (key < arr[i]) {
		return;
	}
	arr[i] = key;
	while (i > -1 && arr[Parent(i)] < arr[i]) {
		swap(arr[i], arr[Parent(i)]);	
		i = Parent(i);
	}
}

void Insert(vector<int>& arr, int key) {
	arr.push_back(INT_MIN);
	IncreaseKey(arr, arr.size()-1, key);	
}

void Delete(vector<int>& arr, int i) {
	if (arr[i] < arr[arr.size()-1]) {
		int l = arr[arr.size()-1];
		arr.erase(arr.begin() + arr.size() - 1);
		IncreaseKey(arr, i, l);
	} else {
		arr[i] = arr[arr.size()-1];
		arr.erase(arr.begin() + arr.size() - 1);
		MaxHeapify(arr,i,arr.size());
	}
}

void Print(vector<int>& arr) {
	for (auto n: arr) {
		cout << n << " ";
	}
	cout << endl;
}

int main(void) {
	vector<int> arr;
	Insert(arr,5);
	Insert(arr,10);
	for (int i = 2; i < 10; i++) {
		Insert(arr, i);
	}
	Print(arr);
	cout << ExtractMax(arr) << endl;
	Print(arr);
	Insert(arr, 69);
	Print(arr);
	Delete(arr, 2);
	Print(arr);
	return 0;
}
