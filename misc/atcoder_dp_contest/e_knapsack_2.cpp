#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e15;

#define MAXN 101
#define MAXV 100001

int N, W, w[MAXN], v[MAXN];
ll dp[MAXN][MAXV];

int main() {
    cin >> N >> W;
    for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= MAXV; j++) {
            dp[i][j] = INF;
        }
    }

    for (int i = 0; i <= N; i++) dp[i][0] = 0;

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < MAXV; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - v[i] >= 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
            }
        }
    }

    for (int i = 1; i <= MAXV; i++) {
        if (dp[N][i] <= W) {
            ans = max(ans, i);
        }
    }

    cout << ans << "\n";
}