#include <bits/stdc++.h>
using namespace std;
vector<int> v[2005];
bool vis[2005];
int level[2005];
void bfs()
{
    queue<int> q;
    q.push(0);
    vis[0] = true;
    level[0] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        // cout << par << endl;
        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs();
    for (int i = 0; i < n; i++)
    {
        if(level[i]==2)
        {
            cout << i <<endl;
        }
    }
    return 0;
}
