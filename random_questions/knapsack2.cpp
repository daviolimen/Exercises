#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

#define MAXN 101
#define MAXV 100001

const ull INF = 1e14;

int N, w[MAXN], v[MAXN];
ull W, dp[MAXN][MAXV];

int main() {
    cin >> N >> W;
    for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXV; j++) {
            dp[i][j] = INF;
        }
    }

    for (int i = 0; i < MAXN; i++) dp[i][0] = 0;

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < MAXV; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - v[i] >= 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + (unsigned long long) w[i]);
            }
            if (dp[i][j] <= W) ans = max(ans, j);
        }
    }

    cout << ans << "\n";
}