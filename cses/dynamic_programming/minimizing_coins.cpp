#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define MAXN 100
#define MAXX 1000001

int n, x, coins[MAXN], dp[MAXX];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> coins[i];

    fill(dp, dp + MAXX, INF);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (auto c : coins) {
            if ((i - c) >= 0) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    if (dp[x] >= INF) cout << -1 << "\n";
    else cout << dp[x] << "\n";
}