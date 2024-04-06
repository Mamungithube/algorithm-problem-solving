#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
    ll int Q;
    cin >> Q;
    vector<ll int> arr;

    for (ll int i = 0; i < Q; ++i)
    {
        ll int valu;
        cin >> valu;
        if (valu == 1)
        {
            ll int X;
            cin >> X;
            arr.push_back(X);
        }
        else if (valu == 2)
        {
            if (arr.empty())
            {
                cout << "empty" << '\n';
            }
            else
            {
                sort(arr.begin(), arr.end());
                ll int minVal = arr[0]; 
                cout << minVal << '\n';
                arr.erase(remove(arr.begin(), arr.end(), minVal), arr.end());
            }
        }
    }

    return 0;
}
