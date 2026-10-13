#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 998244353;

int fact[1000010];

void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= 1000000; i++) fact[i] = (fact[i - 1] * i) % MOD;
}

int xpow(int n, int k) {
    int res = 1;
    while (k > 0) {
        if (k & 1) res = (res * n) % MOD;
        n = (n * n) % MOD;
        k >>= 1;
    }
    return (res + MOD) % MOD;
}

int comb(int n, int k) {
    if ((k < 0) || (k > n)) return 0;
    return ((((fact[n] * xpow(fact[k], MOD - 2)) % MOD) * xpow(fact[n - k], MOD - 2)) % MOD);
}

int32_t main() {
    precompute();
    int tt; cin >> tt;
    while (tt--) {
        int l, r; cin >> l >> r;
        int cpy = l, qnt = 0;
        while (cpy <= r) {
            cpy *= 2;
            qnt++;
        }

        int ans = 0;
        if (qnt > 1) {
            for (int i = 0; i < qnt; i++) {
                int prod = xpow(2, i) * xpow(3, qnt - i - 1);
                
                ans += (max((r / prod) - l + 1, 0ll) * comb(qnt - 1, i));
            }
        } else {
            ans = r - l + 1;
        }
        
        cout << qnt << " " << ans << "\n";
    }
}