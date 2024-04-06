#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
const int N = 1005;
int n, m;
char Ar[N][N];
bool vis[N][N];
pi path[N][N];
vector<pi> d = { {0, 1},{0, -1},{-1, 0},{1, 0}};
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void bfs(int si, int sj)
{
    queue<pi> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        pi par = q.front();
        q.pop();
        for (pi child : d)
        {
            int ci = par.first + child.first;
            int cj = par.second + child.second;
            if (valid(ci, cj) == true && vis[ci][cj] == false && Ar[ci][cj]!='#')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                path[ci][cj] = {child.first, child.second};
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int si, sj, di, dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Ar[i][j];
            if (Ar[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (Ar[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }
    memset(vis,false,sizeof(vis));
    bfs(si, sj);
    if (vis[di][dj])
    {
        vector<pi> tmp;
        while (di != si || dj != sj)
        {       
            tmp.push_back(path[di][dj]);
            di -= tmp.back().first;
            dj -= tmp.back().second;
            Ar[di][dj] = 'X';
        }
        Ar[di][dj] ='R';
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << Ar[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << Ar[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}