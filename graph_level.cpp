#include <bits/stdc++.h>
using namespace std;
vector<int> v[2005];
bool vis[2005];
int level[2005];
void bfs(int root)
{
    queue<int> q;
    q.push(root);
    vis[root] = true;
    level[root] = 0;
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
    int root;
    cin >> root;
    bfs(root);
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << level[i] << endl;
    }
    return 0;
}
