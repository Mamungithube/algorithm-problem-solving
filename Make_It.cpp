#include <bits/stdc++.h>
using namespace std;
int dp[100005];
bool make(int x, int N)
{
    if (x == N)
        return true;
    else if (x > N)
        return false;
    else
    {
        if (dp[x] != -1)
        {
            return dp[x];
        }
        bool op1 = make(x + 3, N);
        bool op2 = make(x * 2, N);
        return dp[x] = op1 || op2;
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        memset(dp, -1, sizeof(dp));
        if (make(1, N))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
