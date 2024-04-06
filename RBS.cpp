#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int openCount = 0, closeCount = 0;
        for (char c : s)
        {
            if (c == '(')
                openCount++;
            else if (c == ')')
                closeCount++;
        }
        if (openCount == closeCount)
        {
            cout << "Possible" << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}
