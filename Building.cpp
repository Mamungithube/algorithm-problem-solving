#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long int parent[N];
long long int group_size[N];
void dsu_initialize(long long int n)
{
    for (long long int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}
long long int dsu_find(long long int node)
{
    if (parent[node] == -1)
        return node;
    long long int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}
void dsu_union(long long int node1, long long int node2)
{
    long long int leaderA = dsu_find(node1);
    long long int leaderB = dsu_find(node2);
    if (group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
class Edge
{
public:
    long long int u, v, w;
    Edge(long long int u, long long int v, long long int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int main()
{
    long long int n, e;
    cin >> n >> e;
    dsu_initialize(n);
    vector<Edge> V;
    while (e--)
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        V.push_back(Edge(u, v, w));
    }
    sort(V.begin(), V.end(), cmp);
    long long int totalCost = 0;
    long long int count = 0;
    for (Edge ed : V)
    {
        long long int leaderU = dsu_find(ed.u);
        long long int leaderV = dsu_find(ed.v);
        if (leaderU == leaderV)
        {
            continue;
        }
        else
        {
            dsu_union(ed.u, ed.v);
            totalCost += ed.w;
            count++;
        }
    }
    if (count == n - 1)
    {
        cout << totalCost << endl;
    }
    else
        cout << "-1" << endl;
    return 0;
}