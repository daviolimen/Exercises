#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
    int t;
    ull x, y;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> y >> x;
        ull diag = 1;
        if (y > x) {
            diag += y * (y - 1);
            if (y % 2 == 0) {
                diag += y - x;
            } else {
                diag -= y - x;
            }
            cout << diag << "\n";
        } else if (x > y) {
            diag += x * (x - 1);
            if (x % 2 == 0) {
                diag -= x - y;
            } else {
                diag += x - y;
            }
            cout << diag << "\n";
        } else {
            diag += y * (y - 1);
            cout << diag << "\n";
        }
    }
}