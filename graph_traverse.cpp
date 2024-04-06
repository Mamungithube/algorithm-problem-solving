#include <bits/stdc++.h>
using namespace std;
vector<int> v[2005];
bool vis[2005];
void bfs(int root)
{
    queue<int> q;
    q.push(root);
    vis[root] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << endl;
        for (int child: v[par])
        {
            if(vis[child]==false)
            {
                q.push(child);
                vis[child]=true;
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
    return 0;
}
