#include <bits/stdc++.h>
using namespace std;

#define MAXN 1001
#define MAXPRICE 100001

int n, x, p[MAXN], v[MAXN], dp[MAXN][MAXPRICE];

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> v[i];

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int P = 1; P <= x; P++) {
            dp[i][P] = dp[i - 1][P];
            if (P - p[i] >= 0) {
                dp[i][P] = max(dp[i][P], dp[i - 1][P - p[i]] + v[i]);
            }
            ans = max(ans, dp[i][P]);
        }
    }
    cout << ans << "\n";
}