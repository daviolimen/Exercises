#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        if (m == 1) {
            bool ok = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] >= b[0]) {
                    ok = 1;
                    break;
                }
            }
            if (ok) cout << "0\n";
            else cout << b[0] << "\n";
            continue;
        }
        vector<int> pref(m, -1), suff(m, -1);
        
        int ia = 0, ib = 0;
        while ((ia < n) && (ib < m)) {
            if (a[ia] >= b[ib]) {
                pref[ib++] = ia;
            }
            ia++;
        }

        ia = n - 1, ib = m - 1;
        while ((ia >= 0) && (ib >= 0)) {
            if (a[ia] >= b[ib]) {
                suff[ib--] = ia;
            }
            ia--;
        }
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (pref[i] == -1) {
                ans = INT_MAX;
                break;
            }
        }

        if (ans == 0) {
            cout << "0\n";
            continue;
        }

        if (suff[1] != -1) ans = min(ans, b[0]);
        if (pref[m - 2] != -1) ans = min(ans, b[m - 1]);
        for (int i = 1; i < m - 1; i++) {
            if (pref[i - 1] == -1) continue;
            if (suff[i + 1] == -1) continue;
            if (pref[i - 1] < suff[i + 1]) ans = min(ans, b[i]);
        }

        if (ans == INT_MAX) cout << "-1\n";
        else cout << ans << "\n";
    }
}