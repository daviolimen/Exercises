// there was no need to use sparse table as we recurse with j on k, so I could just find the max in that loop, well, anyways...

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10001, MAXK = 1001;

int n, k, arr[MAXN], dp[MAXN][MAXK], st[16][MAXN];

int query(int l, int r) {
    int lg = 31 - __builtin_clz(r - l + 1);
    return max(st[lg][l], st[lg][r - (1 << lg) + 1]);
}

int main() {
    ifstream cin("teamwork.in");
    ofstream cout("teamwork.out");
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        st[0][i] = arr[i];
    }

    for (int i = 1; i < 16; i++) {
        for (int j = 1; j <= n; j++) {
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i][j - 1];
            if (i - j < 0) continue;
            dp[i][j] = max(dp[i][j], dp[i - j][k] + j * query(i - j + 1, i));
        }
    }

    cout << dp[n][k] << "\n";
}