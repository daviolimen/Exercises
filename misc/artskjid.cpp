#include <bits/stdc++.h>
using namespace std;

const int MAXN = 19, MAXM = (1 << 19) + 10;

int n, m, mat[MAXN][MAXN], dp[MAXN][MAXM];

int solve(int id, int mask) {
    if (mask == ((1 << n) - 1)) return dp[id][mask] = 0;

    if (dp[id][mask] != -1) return dp[id][mask];

    int res = 0;

    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) || (!mat[id][i])) continue;

        res = max(res, solve(i, (mask | (1 << i))) + mat[id][i]);
    }

    return dp[id][mask] = res;
}

int main() {
    cin >> n >> m;
    int s, d, l;
    for (int i = 0; i < m; i++) {
        cin >> s >> d >> l;
        mat[s][d] = l;
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0, 1) << "\n";

}