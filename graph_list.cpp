#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int>matrix[n];
    while (e--)
    {
        int a,b;
        cin >> a >> b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    int x;
        cin >> x;
        sort(matrix[x].begin(), matrix[x].end(), greater<int>());
    for(int i = 0;i<matrix[x].size();i++)
    {
        cout << matrix[x][i] << " ";
    }
    return 0;
}

