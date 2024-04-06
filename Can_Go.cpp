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
    long long int s;
    cin >> s;
    dis[s] = 0;
    for (int j = 0; j < n - 1; j++)
    {
        for (Edge ed : EdgeList)
        {
            if (dis[ed.u] < INT_MAX && dis[ed.u] + ed.c < dis[ed.v])
            {
                dis[ed.v] = dis[ed.u] + ed.c;
            }
        }
    }
    long long int q;
    cin >> q;
    while (q--)
    {
        long long int d, cost;
        cin >> d >> cost;
        if (dis[d] <= cost)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
