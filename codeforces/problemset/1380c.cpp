#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int tt; cin >> tt;
    while (tt--) {
        int n, x; cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end(), greater<int>());

        int ctr = 0, mn = INT_MAX, ans = 0;
        for (int i = 0; i < n; i++) {
            mn = min(mn, a[i]);
            ctr++;
            if (mn * ctr >= x) {
                ans++;
                ctr = 0;
                mn = INT_MAX;
            }
        }

        cout << ans << "\n";
    }
}