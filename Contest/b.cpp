#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        int mn = LONG_LONG_MAX;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mn = min(mn, a[i]);
        }

        int mn_occ = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == mn) mn_occ++;
        }

        if (mn_occ >= 2) {
            cout << "Yes\n";
            continue;
        }

        int g = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == mn) continue;
            if ((a[i] % mn) == 0) {
                g = gcd(g, a[i]);
            }
        }

        if (g == mn) cout << "Yes\n";
        else cout << "No\n";
    }
}