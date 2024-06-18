#include <bits/stdc++.h>
using namespace std;

long long n, a, b;

long long calc(long long k) {
    return (((2 * b - k + 1) * k) / 2 + (n - k) * a);
}

void solve() {
    if (b - a >= min(n, b)) {
        cout << calc(min(n, b)) << "\n";
    } else if (b - a < 0) {
        cout << calc(0) << "\n";
    } else {
        cout << max(calc(b - a), calc(b - a + 1)) << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        solve();
    }
}