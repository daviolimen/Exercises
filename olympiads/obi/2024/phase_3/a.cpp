#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101, INF = 100000;

int n, arr[MAXN], dp[MAXN][MAXN], st[10][MAXN];

int getMax(int l, int r) {
    int sz = r - l + 1;
    int log2 = 31 - __builtin_clz(sz);
    return max(st[log2][l], st[log2][r - (1 << log2) + 1]);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        st[0][i] = arr[i];
    }

    for (int i = 1; i < 8; i++) {
        for (int j = 1; j <= n; j++) {
            if (j + (1 << (i - 1)) > n) continue;
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = ((i == j) ? 0 : INF);
        }
    }

    for (int sz = 2; sz <= n; sz++) {
        for (int i = 1; i <= n; i++) {
            if (i + sz - 1 > n) continue;
            int j = i + sz - 1;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + abs(getMax(i, k) - getMax(k + 1, j)));
            }
        }
    }

    cout << dp[1][n] << "\n";
}