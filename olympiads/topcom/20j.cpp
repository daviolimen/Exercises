#include <bits/stdc++.h>
using namespace std;

const long long MAXLOG = 66, MOD = (long long) 1e9 + 7;

long long n;
vector<vector<vector<long long>>> dp(MAXLOG, vector<vector<long long>>(3, vector<long long> (3)));


vector<vector<long long>> mult_mat(const vector<vector<long long>> &a, const vector<vector<long long>> &b) {
    vector<vector<long long>> resMat(3, vector<long long>(3, 0));
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                resMat[i][j] += (a[i][k] * b[k][j]);
            }
            resMat[i][j] %= MOD;
        }
    }

    return resMat;
}


int main() {
    cin >> n;
    dp[0][0][0] = 13, dp[0][0][1] = 2, dp[0][0][2] = 1;
    dp[0][1][0] = 2, dp[0][1][1] = 13, dp[0][1][2] = 1;
    dp[0][2][0] = 1, dp[0][2][1] = 1, dp[0][2][2] = 14;

    for (int i = 1; i < MAXLOG; i++) {
        dp[i] = mult_mat(dp[i - 1], dp[i - 1]);
    }

    vector<vector<long long>> resMat(3, vector<long long>(3, 0));
    resMat = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    for (int i = 0; i < 64; i++) {
        if (n & ((long long) 1 << i)) {
            resMat = mult_mat(dp[i], resMat);
        }
    }

    cout << resMat[0][0] << "\n";
}