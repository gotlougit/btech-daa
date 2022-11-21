#include <bits/stdc++.h>
using namespace std;

void line_scheduling(vector<int>& a1, vector<int>& a2, vector<int>& t1, vector<int>& t2, int n, int e1, int e2, int x1, int x2) {
	map<int, int> f1;
	map<int, int> f2;
	map<int, int> l1;
	map<int, int> l2;

	f1[0] = e1 + a1[0];
	f2[0] = e2 + a2[0];

	for (int j = 1; j < n; j++) {
		if (f1[j-1] + a1[j] <= f2[j-1] + t2[j-1] + a1[j]) {
			f1[j] = f1[j-1] + a1[j];
			l1[j] = 1;
		} else {
			f1[j] = f2[j-1] + t2[j-1] + a1[j];
			l1[j] = 2;
		}

		if (f2[j-1] + a2[j] <= f1[j-1] + t1[j-1] + a2[j]) {
			f2[j] = f2[j-1] + a2[j];
			l2[j] = 2;
		} else {
			f2[j] = f1[j-1] + t1[j-1] + a2[j];
			l2[j] = 1;
		}
	}

	int finish = f1[n-1] + x1;
	int leaving = 1;
	if (f1[n-1] + x1 > f2[n-1] + x2) {
		finish = f2[n-1] + x2;
		leaving = 2;
	} 
	cout << "finish time: " << finish << ", leaving from: " << leaving << endl;
}

int main(void) {
	int n = 6;
	int e1 = 2, e2 = 4;
	int x1 = 3, x2 = 2;
	vector<int> a1(n);
	a1[0] = 7;
	a1[1] = 9;
	a1[2] = 3;
	a1[3] = 4;
	a1[4] = 8;
	a1[5] = 4;
	vector<int> a2(n);
	a2[0] = 8;
	a2[1] = 5;
	a2[2] = 6;
	a2[3] = 4;
	a2[4] = 5;
	a2[5] = 7;
	vector<int> t1(n-1);
	t1[0] = 2;
	t1[1] = 3;
	t1[2] = 1;
	t1[3] = 3;
	t1[4] = 4;
	vector<int> t2(n-1);
	t2[0] = 2;
	t2[1] = 1;
	t2[2] = 2;
	t2[3] = 2;
	t2[4] = 1;
	line_scheduling(a1, a2, t1, t2, n, e1, e2, x1, x2);
	return 0;
}
