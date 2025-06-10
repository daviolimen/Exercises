#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        int cnt = 1, val = arr[0], best = LONG_LONG_MAX;
        for (int i = 1; i < n; i++) {
            if (arr[i] == val) {
                cnt++;
            } else {
                best = min(best, val * (n - cnt));
                cnt = 1;
                val = arr[i];
            }
        }

        best = min(best, val * (n - cnt));

        cout << best << "\n";
    }
}