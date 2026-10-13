#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = (int) 1e9 + 7;

int xpow(int n, int k) {
    int res = 1;
    while (k > 0) {
        if (k & 1) res = (res * n) % MOD;
        n = (n * n) % MOD;
        k >>= 1;
    }
    return res;
}

int solve(int l, int r, int k) {
    int razao = (9 / k) + 1;
    int a0 = (9 / k) * xpow((9 / k) + 1, l);
    a0 %= MOD;
    int ans = ((a0 * (xpow(razao, r - l) - 1)) % MOD) * xpow(razao - 1, MOD - 2);
    ans %= MOD;
    return ans;
}

int32_t main() {
    int tt; cin >> tt; 
    while (tt--) {
        int l, r, k; cin >> l >> r >> k;
        cout << solve(l, r, k) << "\n";
    }
}