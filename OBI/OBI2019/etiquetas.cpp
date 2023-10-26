#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10001;
const int INF = (int) 4e8 + 10;

int n, k, c, prefix[MAXN], dp[MAXN][MAXN];

int main() {
    cin >> n >> k >> c;
    for (int i = 1; i <= n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];
    }

    for (int j = 1; j <= k; j++) dp[0][j] = INF;

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];

            if (j && i >= c) {
                dp[i][j] = min(dp[i][j], dp[i - c][j - 1] + prefix[i] - prefix[i - c]);
            }
        }
    }

    cout << prefix[n] - dp[n][k] << "\n";
}