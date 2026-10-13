#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> b(n + 1);
        vector<bool> dp(n + 1);
        for (int i = 1; i <= n; i++) cin >> b[i];
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (i - b[i] - 1 >= 0) dp[i] = dp[i] || dp[i - b[i] - 1];
            if (i + b[i] <= n) dp[i + b[i]] = dp[i + b[i]] || dp[i - 1];
        }

        if (dp[n]) cout << "YES\n";
        else cout << "NO\n";
    }
}