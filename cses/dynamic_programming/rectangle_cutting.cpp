#include <bits/stdc++.h>
using namespace std;

#define MAXN 501

int dp[MAXN][MAXN];

int solve(int x, int y) {
    if (x == y) return 0;
    if (dp[x][y] != -1) return dp[x][y];

    int res = INT_MAX;

    for (int i = 1; i < x; i++) {
        res = min(res, solve(i, y) + solve(x - i, y) + 1);
    }

    for (int i = 1; i < y; i++) {
        res = min(res, solve(x, i) + solve(x, y - i) + 1);
    }

    return dp[x][y] = dp[y][x] = res;
}

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    int a, b; cin >> a >> b;

    cout << solve(a, b) << "\n";
}