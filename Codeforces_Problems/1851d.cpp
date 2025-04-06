#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> pref(n + 1);
        for (int i = 1; i < n; i++) cin >> pref[i];

        bool ans = true;
        vector<bool> ok(n + 1);
        vector<int> sobra;

        for (int i = 1; i < n; i++) {
            int diff = pref[i] - pref[i - 1];
            if (diff <= 0) ans = false;
            else if (diff <= n) {
                if (ok[diff]) sobra.push_back(diff);
                else ok[diff] = 1;
            }
            else sobra.push_back(diff);
        }

        vector<int> falta;
        for (int i = 1; i <= n; i++) if (!ok[i]) falta.push_back(i);


        if (sobra.size() > 1) ans = false;

        if (falta.size() == 2) {
            if (falta[0] + falta[1] != sobra[0]) ans = false;
        } else if (falta.size() != 1) {
            ans = false;
        }

        cout << ((ans) ? "YES\n" : "NO\n");
    }
}