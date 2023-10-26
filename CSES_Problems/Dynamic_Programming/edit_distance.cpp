#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 5002

int dp[MAXN][MAXN];
char a[MAXN], b[MAXN];

int cost(int i, int j) {
    if (a[i - 1] == b[j - 1]) return 0;
    return 1;
}

int main() {
    scanf("%s", a); scanf("%s", b);

    int n = strlen(a), m = strlen(b);

    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= m; i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i - 1][j - 1] + cost(i, j), min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
        }
    }

    cout << dp[n][m] << "\n";
}