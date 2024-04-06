#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    long long int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const int N = 1e7 + 5;
long long int dis[N];
int main()
{
    long long int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        long long int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }
    for (int i = 0; i <= n; i++)
    {
        dis[i] = 1e18;
    }
    long long int src;
    cin >> src;
    dis[src] = 0;
    for (int j = 0; j < n - 1; j++)
    {
        for (Edge ed : EdgeList)
        {
            if (dis[ed.u] < 1e18 && dis[ed.u] + ed.c < dis[ed.v])
            {
                dis[ed.v] = dis[ed.u] + ed.c;
            }
        }
    }
    bool cycle = false;
    for (Edge ed : EdgeList)
    {
        long long int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if (dis[u] < 1e18 && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        long long int S;
        cin >> S;
        if (cycle)
        {
            cout << "Negative Cycle Detected" << endl;
            break;
        }
        else
        {
            if (dis[S] == 1e18)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[S] << endl;
            }
        }
    }
    return 0;
}
