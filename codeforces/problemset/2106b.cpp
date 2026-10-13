#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, x; cin >> n >> x;
        vector<int> ans(n);
        if (x == n) {
            for (int i = 0; i < n; i++) ans[i] = i;
        } else {
            int curr = 0;
            for (int i = 0; i < n - 1; i++) {
                if (i == x) curr++;
                ans[i] = curr;
                curr++;
            }
            ans[n - 1] = x;
        }
        for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == (n - 1)];
    }
}