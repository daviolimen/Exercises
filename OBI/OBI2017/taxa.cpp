#include <bits/stdc++.h>
using namespace std;

#define MAXN 201

int n, arr[2 * MAXN], prefix[2 * MAXN];
double f, dp[MAXN][MAXN];

double solve(int x, int y) {
    if (x == y) return 0;
    if (dp[x][y] != -1) return dp[x][y];

    double res = 1e9;

    int X = x, Y = (y > x) ? y : y + n;

    for (int i = x; i < Y; i++) {
        int maior = max(prefix[Y + 1] - prefix[i + 1], prefix[i + 1] - prefix[x]);
        res = min(res, solve(x, i % n) + solve(((i % n) + 1) % n, y) + (double) maior * f);
    }

    return dp[x][y] = res;
}

int main() {
    scanf("%d %lf", &n, &f);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        arr[i + n] = arr[i];
    }

    for (int i = 0; i < 2 * n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    double ans = 1e9;

    for (int i = 0; i < n; i++) {
        ans = min(ans, solve(i, (i + n - 1) % n));
    }

    printf("%.2lf\n", ans);
}