#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int A[n][n];
    for (int i = 0; i < (n * 2)-1; i++)
    {
        for (int  j= 0; j < n*3; j++)
        {
            cout << '*' ;
        }
        cout << endl;
    }
    return 0;
}