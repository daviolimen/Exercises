#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 101
#define MAXW 100001

int N, W, w[MAXN], v[MAXN];
ll dp[MAXN][MAXW];

int main() {
    cin >> N >> W;
    for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - w[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[N][W] << "\n";
}