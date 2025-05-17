#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, x; cin >> n >> x;
        int cnt = __builtin_popcount(x);
        if (x == 0) {
            if (n == 1) {
                cout << "-1\n";
            } else if (n % 2 == 0) {
                cout << n << "\n";
            } else {
                cout << 6 + (n - 3) << "\n";
            }
            continue;
        }
        if (x == 1) {
            if (n % 2 == 0) {
                cout << 5 + (n - 2) << "\n";
            } else {
                cout << n << "\n";
            }
            continue;
        }
        if (n - cnt >= 0) {
            if ((n - cnt) % 2) {
                cout << x + (n - cnt + 1) << "\n";
            } else {
                cout << x + n - cnt << "\n";
            }
        } else {
            cout << x << "\n";
        }
    }
}