#include <bits/stdc++.h>
using namespace std;

const int MAXN = 51;

int N, K, T, P[MAXN];
pair<int, long long> dp[MAXN][1001];
bool G[MAXN];

int main() {
    cin >> N >> K >> T;
    for (int i = 1; i <= N; i++) cin >> P[i];
    for (int i = 1; i <= N; i++) cin >> G[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= T; j++) {
            if (!G[i]) {
                dp[i][j] = dp[i - 1][j];
                continue;
            }

            for (int k = 1; k <= N; k++) {
                int tSob = j - abs(i - k);
                if (tSob < 0) continue;
                auto par = dp[i - 1][tSob];
                if (par.second & (1LL << k)) continue;
                if (dp[i][j].first < par.first + P[k]) {
                    dp[i][j].first = par.first + P[k];
                    dp[i][j].second = ((par.second) | (1LL << k));
                }
            }
        }
    }

    cout << dp[N][T].first << "\n";
}