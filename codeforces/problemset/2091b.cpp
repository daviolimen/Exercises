#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, x; cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end(), greater<int>());

        int mn = INT_MAX, ctr = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            mn = min(mn, arr[i]);
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