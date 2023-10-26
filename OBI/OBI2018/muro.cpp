#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10001;
const int MOD = (int) 1e9 + 7;

int n;
long long dp[MAXN];

int main() {
    dp[0] = dp[1] = 1;
    dp[2] = 5;

    cin >> n;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + 4 * dp[i - 2] + 2 * dp[i - 3]) % MOD;
    }

    cout << dp[n] << "\n";
}