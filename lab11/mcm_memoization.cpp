#include <bits/stdc++.h>
using namespace std;
static int res[5][5];
int solve(int arr[], int i, int j)
{
    if (i >= j)
       return res[i][j]=0;
    int mini = INT_MAX;
    int temp;
    if(res[i][j]!=-1)
        return res[i][j];
    for (int k = i; k < j; k++)
    {
         temp = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
      mini=min(temp,mini);
    }
    return res[i][j]=mini;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 3};
     memset(res,-1,sizeof(res));
    cout << solve(arr, 1, 4);
   
    return 0;
}