#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
const int maxv = 1000;
int dp[maxn][maxv];
int knapsack(int n, int ni[], int vi[], int w)
{
    if (n == 0 || w == 0)
        return 0;
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (ni[n - 1] <= w)
    {
        int op1 = knapsack(n - 1, ni, vi, w - ni[n - 1]) + vi[n - 1];
        int op2 = knapsack(n - 1, ni, vi, w);
        return dp[n][w] = max(op1, op2);
    }
    else
    {
        int op2 = knapsack(n - 1, ni, vi, w);
        return dp[n][w] = op2;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,w;
        cin >> n >> w;
        int ni[1005],wi[1005];
        for(int i = 0;i<n;i++)
        {
            cin >> ni[i];
        }
        for(int i = 0;i<n;i++)
        {
            cin >> wi[i];
        }
        for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << knapsack(n, ni, wi, w) << endl;
    }
    return 0;
}