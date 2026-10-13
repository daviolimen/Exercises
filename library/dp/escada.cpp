#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

int n, dp[MAXN][MAXN];
bool mark[MAXN][MAXN];

int solve(int x, int prev = 0) {
    if (x == n) return 1;
    if (x > n) return 0;

    if (mark[x][prev]) return dp[x][prev];
    mark[x][prev] = 1;

    for (int i = x + prev + 1; i <= n; i++) {
        dp[x][prev] += solve(i, i - x);
    }
    return dp[x][prev];
}

int main() {
    cin >> n;
    cout << solve(1) << "\n";
}