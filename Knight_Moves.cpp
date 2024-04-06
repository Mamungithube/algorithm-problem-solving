#include <bits/stdc++.h>
using namespace std;
const int N = 105;
bool vis[N][N];
int dis[N][N];
vector<pair<int, int>> d = {{-1, -2}, {-2, -1}, {1, -2}, {2, -1}, {2, 1}, {-1, 2}, {-2, 1}, {1, 2}};
int n, m;
bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y];
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        for (int i = 0; i < d.size(); ++i)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;
            if (valid(ci, cj))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[par.first][par.second] + 1;
            }
        }
    }
}

int main()
{
    int Q;
    cin >> Q;
    while (Q--)
    {
        cin >> n >> m;
        memset(dis, -1, sizeof(dis));
        memset(vis, false, sizeof(vis));
        int si, sj, qi, qj;
        cin >> si >> sj >> qi >> qj;
        bfs(si, sj);
        if (dis[qi][qj] != -1)
        {
            cout << dis[qi][qj] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
