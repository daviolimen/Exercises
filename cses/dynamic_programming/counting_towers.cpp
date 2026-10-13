#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

#define MAXT 100
#define MAXN 1000001

int n, tests[MAXT];
long long dp[MAXN][2];

int main() {
    int t; cin >> t;
    int mx = 0;
    for (int i = 0; i < t; i++) {
        cin >> tests[i];
        mx = max(mx, tests[i]);
    }
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= mx; i++) {
        dp[i][0] = ((dp[i - 1][1] % MOD) + (4 * (dp[i - 1][0] % MOD))) % MOD;
        dp[i][1] = ((dp[i - 1][0] % MOD) + (2 * (dp[i - 1][1] % MOD))) % MOD;
    }

    for (int i = 0; i < t; i++) {
        cout << (dp[tests[i]][0] + dp[tests[i]][1]) % MOD << "\n";
    }
}