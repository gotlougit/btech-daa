#include <iostream>
using namespace std;
static int arr[7][8];
void lcs(string X, string Y, int i, int j)
{
    if (i == 0 || j == 0)
        arr[i][j] = 0;

    if (X[i - 1] == Y[j - 1])
        arr[i][j] = 1 + arr[i - 1][j - 1];
    else
    {
        arr[i][j] = max((arr[i][j - 1]),
                        (arr[i - 1][j]));
    }
}

int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    // Find the length of string
    int m = X.length();
    int n = Y.length();
    // memset(arr,-1,sizeof(arr));
    for (int i = 1; i < m + 1; i++)
        for (int j = 1; j < n + 1; j++)
        {
            lcs(X, Y, i, j);
        }
    cout << arr[m][n];

    return 0;
}