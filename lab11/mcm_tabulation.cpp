//not working
#include <iostream>
using namespace std;
static int res[5][5];
void solve(int arr[], int i, int j)
{
    if (i >= j)
        res[i][j]= 0;
    int mini = INT_MAX;
    int temp;
    for (int k = i; k < j; k++)
    {
        temp = res[i][k] + res[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
      mini=min(temp,mini);
      res[i][j]=mini;
    }
   
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 3};
    //cout<< solve(arr, 1, 4);

   for (int i = 2; i < 5; i++)
        for (int j = 1; j < 5; j++)
        {solve(arr,i,j);}
        cout<<res[4][4];
    return 0;
}