#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        int mn = INT_MAX, mx = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                mn = min(mn, i);
                mx = max(mx, i);
            }
        }

        if (mx - mn + 1 > k) cout << "NO\n";
        else cout << "YES\n";
    }
}