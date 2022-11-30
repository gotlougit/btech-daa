#include <iostream>
using namespace std;
int getMinTime(int t[4][4], int trans[3][3], int x[], int line, int station)
{
    if (station == 4 - 1)
    {
        return t[line][station] + (line == 0 ? x[0] : x[1]);
    }
    int path1=getMinTime(t, trans, x,line,station+1);
    int path2=trans[line][station]+getMinTime(t, trans, x,1-line,station+1);

    return t[line][station]+min(path1,path2);
}

int main()
{
    int e[2] = {10, 12};
    int x[2] = {18, 7};
    int t[4][4] = {{4, 5, 3, 2}, {2, 10, 1, 4}};
    int trans[3][3] = {{7, 4, 5}, {9, 2, 8}};
    int r1 = e[0] + getMinTime(t, trans, x, 0, 0);
    int r2 = e[1] + getMinTime(t, trans,x, 1, 0);
    cout << min(r1, r2);
    return 0;
}