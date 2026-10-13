#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;

        int last = arr[0], ans = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] - last <= 1) continue;
            else {
                ans++;
                last = arr[i];
            }
        }

        cout << ans << "\n";
    }
}