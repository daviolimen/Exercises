#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int n;
double mat[17][17], dp[17][(1 << 17)];
pi cd[17];

double dist(pi a, pi b) {
    return hypot(a.first - b.first, a.second - b.second);
}

double solve(int id, int mask) {
    if (mask == ((1 << n) - 1)) {
        return mat[id][0];
    }

    if (dp[id][mask] != -1) return dp[id][mask];

    double res = 1e14;

    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) continue;

        res = min(res, solve(i, mask | (1 << i)) + mat[id][i]);
    }

    return dp[id][mask] = res;
}

int main() {
    cin >> n;
    while (n != 0) {
        ++n;
        for (int i = 0; i < n; i++) {
            cin >> cd[i].first >> cd[i].second;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                mat[i][j] = mat[j][i] = dist(cd[i], cd[j]);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                dp[i][j] = -1;
            }
        }

        printf("%.2lf\n", solve(0, 1));

        cin >> n;
    }
}