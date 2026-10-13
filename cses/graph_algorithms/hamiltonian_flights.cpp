#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = (int) 1e9 + 7, MAXN = 20, MAXM = 1 << 20;

ll dp[MAXM][MAXN];
vector<int> pai[MAXN];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        pai[--b].push_back(--a);
    }

    dp[1][0] = 1;
    for (int s = 2; s < (1 << n); s++) {
        if ((s & 1) == 0) continue;
        if ((s & (1 << (n - 1))) && (s != ((1 << n) - 1))) continue;

        for (int i = 0; i < n; i++) {
            if ((s & (1 << i)) == 0) continue;
            for (auto v : pai[i]) {
                if (s & (1 << v)) {
                    dp[s][i] += dp[s - (1 << i)][v];
                    dp[s][i] %= MOD;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << "\n";
}