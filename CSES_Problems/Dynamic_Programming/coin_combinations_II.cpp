#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
const int MAXX = 1e6 + 10;
const int MOD = 1e9 + 7;

int n, x, coins[MAXN], dp[MAXX];

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> coins[i];

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j - coins[i] >= 0) {
                dp[j] += dp[j - coins[i]];
                dp[j] %= MOD;
            }
        }
    }
    cout << dp[x] << "\n";
}