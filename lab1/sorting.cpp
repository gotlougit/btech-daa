#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr) {
	for (int i = 1; i < arr.size(); i++) {
		int j = i-1;
		int key = arr[i];
		while (j > -1 && arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void selectionSort(vector<int> &arr) {
	for (int i = 0; i < arr.size(); i++) {
		int min = i;
		for (int j = i+1; j < arr.size(); j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

void bubbleSort(vector<int> &arr)
{
	for (int i = 0; i < n - 1; i++){
        	for (int j = 0; j < n - i - 1; j++){
            		if (arr[j] > arr[j + 1])
                	swap(arr[j], arr[j + 1]);
		}
	}
}

void printArr(vector<int> &arr) {
	for (auto num: arr) {
		cout << num << " ";
	}
	cout << endl;
}

//http://stackoverflow.com/questions/14096821/ddg#14096847
int getIntegerFromStdin(void) {
	int input = 0;
	while (!(cin >> input)) {
		cout << "Invalid integer value, please enter again" << endl;
		cin.clear();
		cin.ignore();
	}
	return input;
}

void fillArr(vector<int> &arr) {
	int size;
	cout << "Enter size: ";
	size = getIntegerFromStdin();
	cout << "Enter all elements: " << endl;
	for (int i = 0; i < size; i++) {
		int input = getIntegerFromStdin();
		arr.push_back(input);
	}
}

int main(void) {
	
	vector<int> arr;
	vector<int> arr2;
	fillArr(arr);
	fillArr(arr2);
	
	cout << "First array, sorting using selection sort" << endl;
	cout << "Before: " << endl;
	printArr(arr);
	selectionSort(arr);
	cout << "After: " << endl;
	printArr(arr);
	
	cout << "Second array, sorting using insertion sort" << endl;
	cout << "Before: " << endl;
	printArr(arr2);
	insertionSort(arr2);
	cout << "After: " << endl;
	printArr(arr2);

	return 0;
}
