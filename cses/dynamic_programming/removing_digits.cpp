// OBS: Tambem da pra resolver usando greedy e sempre subtraindo o maior algarismo

#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000001

const int INF = 1e9;

int n, dp[MAXN];

int main() {
    cin >> n;
    fill(dp+1, dp+n+1, INF);
    for (int i = 1; i <= n; i++) {
        int cpy = i;
        vector<int> algs;
        while (cpy > 0) {
            algs.push_back(cpy % 10);
            cpy /= 10;
        }
        for (auto a : algs) {
            dp[i] = min(dp[i], dp[i - a] + 1);
        }
    }

    cout << dp[n] << "\n";
}