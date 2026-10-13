#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300;

int n, arr[MAXN], dp[MAXN][MAXN];

int solve(int x, int y) {
    if (x == y) return 1;
    if (dp[x][y] != -1) return dp[x][y];

    int res = INT_MAX;

    for (int i = x; i < y; i++) {
        if (arr[x] == arr[y]) {
            res = min(res, solve(x, i) + solve(i + 1, y) - 1);
        }
        res = min(res, solve(x, i) + solve(i + 1, y));
    }

    return dp[x][y] = res;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << solve(0, n - 1) << "\n";
}