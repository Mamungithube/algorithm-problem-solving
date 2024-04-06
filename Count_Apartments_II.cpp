#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int ar[N][N];
int vis[N][N];
int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int cnt = 0;
bool valid(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && ar[x][y] != -1)
        return true;
    return false;
}
void dfs(int x, int y)
{
    cnt++;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (valid(new_x, new_y))
        {
            dfs(new_x, new_y);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#')
            {
                ar[i][j] = -1;
            }
            else
            {
                ar[i][j] = 0;
            }
        }
    }
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && ar[i][j] != -1)
            {
                cnt = 0;
                dfs(i, j);
                v.push_back(cnt);
            }
        }
    }
    sort(v.begin(), v.end());
    if (v.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }
    return 0;
}
