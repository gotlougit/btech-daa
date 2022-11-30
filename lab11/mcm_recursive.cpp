#include <iostream>
using namespace std;

int solve(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    int mini = INT_MAX;
    int temp;
    for (int k = i; k < j; k++)
    {
        temp = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
       mini=min(temp,mini);
    }
    return mini;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 3};
    cout << solve(arr, 1, 4);

    return 0;
}