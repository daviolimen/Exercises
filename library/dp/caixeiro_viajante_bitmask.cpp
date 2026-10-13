#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 16, maxm = (1 << 15) + 10;

int n, m;
int mat[maxn][maxn], dp[maxm][maxn];

int solve(int mask, int i) {
    if (mask == (1 << n) - 1) return dp[mask][i] = 0;

    if (dp[mask][i] != -1) return dp[mask][i];

    int ans = 1e9;

    for (int v = 0; v < n; v++) {
        if (mask & (1 << v) || !mat[i][v]) continue;

        ans = min(ans, solve((mask || (1 << v)), v) + mat[i][v]);
    }

    return dp[mask][i] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        mat[a][b] = mat[b][a] = w;
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(1, 0) << "\n";
}