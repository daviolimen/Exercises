#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

#define MAXN 101
#define MAXW 100001

int N, W, w[MAXN], v[MAXN];
ull dp[MAXN][MAXW];

int main() {
    cin >> N >> W;
    for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];

    for (int i = 1; i <= N; i++) {
        for (int c = 1; c <= W; c++) {
            dp[i][c] = dp[i - 1][c];
            if (c - w[i] >= 0) {
                dp[i][c] = max(dp[i][c], dp[i - 1][c - w[i]] + v[i]);
            }
        }
    }
    cout << dp[N][W] << "\n";
}