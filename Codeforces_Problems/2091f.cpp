#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2000, MOD = 998244353;

char grid[MAXN][MAXN];
int n, m, d, dp[MAXN][MAXN][2];
long long pref[MAXN][MAXN][2];

int getSum(int x, int y1, int y2, int z) {
    y1 = max(0ll, y1);
    y2 = min(m - 1, y2);
    int res = pref[x][y2][z];
    if (y1) res -= pref[x][y1 - 1][z];
    return res % MOD;
}

int get(int x, int y, int z) {
    if (grid[x][y] == '#') {
        return dp[x][y][0] = dp[x][y][1] = 0;
    }

    if (z == 0) {
        if (x == n - 1) dp[x][y][0] = 1;
        else dp[x][y][0] = getSum(x + 1, y - d + 1, y + d - 1, 0) + getSum(x + 1, y - d + 1, y + d - 1, 1);
    } else {
        dp[x][y][1] = getSum(x, y - d, y + d, 0) - dp[x][y][0];
    }

    return dp[x][y][z];
}

void solve() {
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (j > 0) pref[i][j][0] = pref[i][j - 1][0] + get(i, j, 0);
            else pref[i][j][0] = get(i, j, 0);
            pref[i][j][0] %= MOD;
        }

        for (int j = 0; j < m; j++) {
            if (j > 0) pref[i][j][1] = pref[i][j - 1][1] + get(i, j, 1);
            else pref[i][j][1] = get(i, j, 1);
            pref[i][j][1] %= MOD;
        }
    }

    int ans = 0;
    for (int j = 0; j < m; j++) ans = (ans + (dp[0][j][0] + dp[0][j][1]) % MOD) % MOD;
    cout << (ans + MOD) % MOD << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
}