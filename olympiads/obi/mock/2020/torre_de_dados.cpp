#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

int n, dados[MAXN][6], dp[MAXN][7];

int getOppIdx(int idx) {
    switch (idx) {
        case 0:
            return 5;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 0;
        default:
            cout << "WTH\n";
            return -1;
    }
}

int getOpp(int dice, int val) {
    for (int j = 0; j < 6; j++) {
        if (dados[dice][j] == val) return dados[dice][getOppIdx(j)];
    }
    return -1;
}

int getMaxWithout(int dice, int val) {
    int val2 = getOpp(dice, val);
    if (val + val2 == 11) return 4;
    if (max(val, val2) == 6) return 5;
    return 6;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) cin >> dados[i][j];
    }

    for (int j = 1; j <= 6; j++) dp[0][j] = getMaxWithout(0, j);

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= 6; j++) {
            dp[i][j] = dp[i - 1][getOpp(i, j)] + getMaxWithout(i, j);
        }
    }

    int ans = -1;
    for (int j = 1; j <= 6; j++) ans = max(ans, dp[n - 1][j]);
    cout << ans << "\n";
}