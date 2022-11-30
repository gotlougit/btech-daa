#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "enter size of array";
    int n;
    cin >> n;
    int max = INT_MIN;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    // cout<<max;
    int temp[max + 1];
    //initializing count array to zero
    for(int i=0;i<=max;i++)
    temp[i]=0;
   // memset(temp, 0, max+1);
    for (int i = 0; i < n; i++)
    {
        int v = arr[i];
        temp[v]=temp[v]+1;
    }
    // for(int i=0;i<=max;i++)
    // {
    //     cout<<temp[i]<<" ";

    // }
    for (int i = 0; i <= max; i++)
    {
        if (temp[i] != 0)
        {
            int count = temp[i];
            for (int j = 0; j < count; j++)
                cout << i<<" ";
        }
    }
    return 0;
}