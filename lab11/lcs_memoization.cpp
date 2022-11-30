
#include <bits/stdc++.h>
using namespace std;
static int arr[7][8];


// Returns length of LCS for X[0..m-1], Y[0..n-1]
int lcs(string X, string Y, int m, int n)
{
	if (m == 0 || n == 0)
		return arr[m][n]= 0;

        if(arr[m][n]!=-1)
        return arr[m][n];
else
	{if (X[m - 1] == Y[n - 1])
		return arr[m][n]=1 + lcs(X, Y, m - 1, n - 1);
	else
		return arr[m][n]=max(lcs(X, Y, m, n - 1),
				lcs(X, Y, m - 1, n));}
}

// Driver Code
int main()
{
	string X = "AGGTAB";
	string Y = "GXTXAYB";
	// Find the length of string
	int m = X.length();
	int n = Y.length();
    memset(arr,-1,sizeof(arr));
  


	cout << "Length of LCS: " << lcs(X, Y, m, n);
//cout<<arr[m][n];
	return 0;
}
