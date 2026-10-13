#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int tt; cin >> tt;
    while (tt--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int a = x2 - x1, b = y2 - y1;
        cout << a * b + 1 << "\n";
    }
}