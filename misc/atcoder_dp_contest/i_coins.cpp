#include <bits/stdc++.h>
using namespace std;

#define MAXN 3000

int n;
double probs[MAXN], dp[MAXN][MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> probs[i];

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] * (1 - probs[i]);
            if (j > 0) dp[i][j] += dp[i - 1][j - 1] * probs[i];
        }
    }

    double ans = 0;
    for (int i = 0; i <= n; i++) {
        if (i > (n - i)) ans += dp[n][i];
    }

    cout << fixed << setprecision(10) << ans << "\n";
}
