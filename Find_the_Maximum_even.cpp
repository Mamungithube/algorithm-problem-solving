#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max_even = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0 && arr[i] > max_even)
        {
            max_even = arr[i];
        }
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[i] + arr[j]) % 2 == 0 && arr[i] + arr[j] > max_even)
            {
                max_even = arr[i] + arr[j];
            }
        }
    }
    cout << max_even << endl;
    return 0;
}