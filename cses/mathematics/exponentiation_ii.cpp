#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = (int) 1e9 + 7;

int xpow(int x, int y, int m) {
    int res = 1;
    while (y > 0) {
        if (y & 1) res *= x;
        y >>= 1;
        x *= x;
        res %= m;
        x %= m;
    }
    return res;
}

int32_t main() {
    int n; cin >> n;
    while (n--) {
        int a, b, c; cin >> a >> b >> c;
        cout << xpow(a, xpow(b, c, MOD - 1), MOD) << "\n";
    }
}