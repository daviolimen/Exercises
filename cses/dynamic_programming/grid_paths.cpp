#include <bits/stdc++.h>
using namespace std;

#define MAXN 1001

int n;
long long dp[MAXN][MAXN];
char grid[MAXN][MAXN];

const int mod = 1e9 + 7;

bool isSafe(int y, int x) {
    if ((y < 0) || (y >= n) || (x < 0) || (x >= n)) return false;
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    if (grid[1][1] == '*') dp[1][1] = 0;
    else dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i == 1) && (j == 1)) continue;
            if (grid[i][j] == '*') continue;
            dp[i][j] = ((dp[i - 1][j] % mod) + (dp[i][j - 1] % mod)) % mod;
        }
    }

    cout << dp[n][n] << "\n";
}