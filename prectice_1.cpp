#include <bits/stdc++.h>
using namespace std;

vector<int> v[2005];
bool vis[2005];
int level[2005];
int parent[2005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    // Input the edges
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int q;
    cin >> q; // Number of queries

    while (q--)
    {
        int src, dis;
        cin >> src >> dis;

        // Reset arrays for each query
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        memset(parent, -1, sizeof(parent));

        bfs(src);

        if (level[dis] != -1)
        {
            cout << level[dis] << endl;
        }
    }
    cout << endl;
    return 0;
}
