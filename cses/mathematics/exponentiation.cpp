#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = (int) 1e9 + 7;

ll xpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = ((res % MOD) * (a % MOD)) % MOD;
        b >>= 1;
        a = ((a % MOD) * (a % MOD)) % MOD;
    }
    return (res % MOD);
}

int main() {
    int n; cin >> n;
    while (n--) {
        int a, b; cin >> a >> b;
        cout << xpow(a, b) << "\n";
    }
}