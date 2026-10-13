#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5001, INF = (int) 1e16;

int n, arr[MAXN];
long long prefix[MAXN], dp[MAXN][MAXN];

long long solve(int x, int y) {
    if (x == y) return arr[x];
    if (dp[x][y] != INF) return dp[x][y];

    dp[x][y] = max(arr[x] + (prefix[y] - prefix[x] - solve(x + 1, y)), (prefix[y - 1] - prefix[x - 1] - solve(x, y - 1)) + arr[y]);
    return dp[x][y];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i];
    }

    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j < MAXN; j++) dp[i][j] = INF;
    }

    cout << solve(1, n) << "\n";
}