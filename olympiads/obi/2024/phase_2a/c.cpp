#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 100100;

int n, q, d[MAXN], pref[MAXN];

int32_t main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        pref[i] = pref[i - 1] + d[i];
    }

    while (q--) {
        int l, r; cin >> l >> r;
        int ans = (pref[r] - pref[l - 1]) * (r - l) * 11;
        cout << ans << "\n";
    }
}