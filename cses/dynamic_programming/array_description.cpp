#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001
#define MAXM 101

const int mod = 1e9 + 7;

int n, m, arr[MAXN];
long long dp[MAXN][MAXM];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    if (arr[1] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[1][i] = 1;
        }
    } else {
        dp[1][arr[1]] = 1;
    }

    for (int i = 2; i <= n; i++) {
        if (arr[i] != 0) {
            dp[i][arr[i]] = (dp[i - 1][arr[i] - 1] % mod + dp[i - 1][arr[i]] % mod + dp[i - 1][arr[i] + 1] % mod) % mod;
            continue;
        }
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod + dp[i - 1][j + 1] % mod) % mod;
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << "\n";
}