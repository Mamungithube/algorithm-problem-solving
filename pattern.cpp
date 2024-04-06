#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;

    // Printing the upper half of the pattern
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            cout << " ";
        }
        cout << i % 3;
        for (int j = 0; j < 2 * (n - i); j++) {
            cout << " ";
        }
        if (i != n)
            cout << i % 3;
        
        cout << endl;
    }

    // Printing the lower half of the pattern
    for (int i = n - 1; i > 0; i--) {
        for (int j = 1; j < i; j++) {
            cout << " ";
        }
        cout << i % 3;
        for (int j = 0; j < 2 * (n - i); j++) {
            cout << " ";
        }
        if (i != n)
            cout << i % 3;
        
        cout << endl;
    }

    return 0;
}
