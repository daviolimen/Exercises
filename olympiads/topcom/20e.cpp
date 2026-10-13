#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001, MAXG = 101, MAXW = 31;

int n, g, v[MAXN], w[MAXN], carga[MAXG], dp[MAXN][MAXW];

int main() {
    int t; cin >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
        cin >> g;
        for (int i = 1; i <= g; i++) cin >> carga[i];

        for (int i = 1; i <= n; i++) {
            for (int peso = 1; peso < MAXW; peso++) {
                dp[i][peso] = dp[i - 1][peso];
                if (peso - w[i] >= 0) {
                    dp[i][peso] = max(dp[i][peso], dp[i - 1][peso - w[i]] + v[i]);
                }
            }
        }

        int res = 0;

        for (int i = 1; i <= g; i++) {
            res += dp[n][carga[i]];
        }

        cout << res << "\n";
    }
}