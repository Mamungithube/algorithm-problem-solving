#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int A[n][n];
    memset(A, 0, sizeof(A));
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        A[a][b] = 1;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (A[x][y] == 1 || A[x]==A[y])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}