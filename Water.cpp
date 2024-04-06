#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        priority_queue<pair<int, int>> pq;
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            pq.push(make_pair(a[i], i));
        }
        int first = pq.top().second;
        pq.pop();
        int second = pq.top().second;
        if (first < second)
        {
            cout << first << " " << second;
        }
        else
        {
            cout << second << " " << first;
        }
        cout << endl;
    }
    return 0;
}
