#include <bits/stdc++.h>
using namespace std;
int lcs(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;

    if (x[n - 1] == y[m - 1])
    {
        return 1 + lcs(x, y, n - 1, m - 1);
    }
    else
    {
        return max(lcs(x, y, n, m - 1), lcs(x, y, n - 1, m));
    }
}
int main()
{
    string x = "aggtab";
    string y = "gxtxayb";
    int n = x.length();
   
    int m = y.length();
    
    cout << lcs(x, y, m, n);
    return 0;
}
// A Naive C++ recursive implementation
// of LCS of two strings
// #include <bits/stdc++.h>
// using namespace std;

// // Returns length of LCS for X[0..m-1], Y[0..n-1]
// int lcs(string X, string Y, int m, int n)
// {
// 	if (m == 0 || n == 0)
// 		return 0;

// 	if (X[m - 1] == Y[n - 1])
// 		return 1 + lcs(X, Y, m - 1, n - 1);
// 	else
// 		return max(lcs(X, Y, m, n - 1),
// 				lcs(X, Y, m - 1, n));
// }

// // Driver Code
// int main()
// {
// 	string X = "AGGTAB";
// 	string Y = "GXTXAYB";

// 	// Find the length of string
// 	int m = X.length();
// 	int n = Y.length();

// 	cout << "Length of LCS: " << lcs(X, Y, m, n);

// 	return 0;
// }
