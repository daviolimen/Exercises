#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

ll xpow(ll x, unsigned int y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1) res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

void solve(ll k) {
    ll casas = 1;
    for (ll p = 9;; k -= p, casas++, p = 9 * xpow(10, casas - 1) * casas) {
        if (k - p <= 0) break;
    }
    k--;

    ll x = k / casas;
    ll y = k % casas;
    ll num = xpow(10, casas - 1) + x;
    string ans = to_string(num);

    cout << ans[y] << "\n";
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll q; cin >> q;
    ll k;
    while (q--) {
        cin >> k;
        solve(k);
    }
}