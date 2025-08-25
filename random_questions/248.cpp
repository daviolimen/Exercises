#include <bits/stdc++.h>
using namespace std;

#define MAXN 249

int n, arr[MAXN];
pair<int, bool> dp[MAXN][MAXN];

pair<int, bool> solve(int x, int y) {
    if (x == y) return {arr[x], true};
    if (dp[x][y].first != 0) return dp[x][y];

    pair<int, bool> res;

    for (int i = 0; x + i < y; i++) {
        if ((solve(x, x + i).first == solve(x + i + 1, y).first) && (solve(x, x + i).second && solve(x + i + 1, y).second)) {
            if (solve(x, x + i).first + 1 > res.first) {
                res.first = solve(x, x + i).first + 1;
                res.second = true;
            }
        }
        if (solve(x, x + i).first > res.first) {
            res.first = solve(x, x + i).first;
            res.second = false;
        }
        if (solve(x + i + 1, y).first > res.first) {
            res.first = solve(x + i + 1, y).first;
            res.second = false;
        }
    }

    return dp[x][y] = res;
}

int main() {
    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    cout << solve(1, n).first << "\n";
}