#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e7;
bool visi[N];
int main()
{
  long long int q;
  cin >> q;
  priority_queue<int, vector<int>, greater<int>> pq;
  long long int mn;
  while (q--)
  {
    long long int qt;
    cin >> qt;
    memset(visi, false, sizeof(visi));
    if (qt == 1)
    {
      long long int x;
      cin >> x;
      if (!visi[x])
      {
        pq.push(x);
        visi[x] = true;
      }
    }
    else
    {
      if (pq.empty())
      {
        cout << "empty" << endl;
      }
      else
      {
        long long int mini = pq.top();
        cout << pq.top() << endl;
        while (!pq.empty() && pq.top() == mini)
        {
          pq.pop();
        }
      }
    }
  }
  return 0;
}