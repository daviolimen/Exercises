#include <bits/stdc++.h>
using namespace std;

#define int long long

bool comp[10001];

int32_t main() {
    ifstream cin("exercise.in");
    ofstream cout("exercise.out");
    int N, M;
    cin >> N >> M;

    vector<int> primes{1};
    for (int i = 2; i <= N; i++) {
        if (comp[i]) continue;
        primes.push_back(i);
        for (int j = 2 * i; j <= N; j += i) {
            comp[j] = 1;
        }
    }

    vector<vector<int>> dp(primes.size(), vector<int>(N + 1, 1));

    for (int i = 1; i < primes.size(); i++) {
        for (int j = 1; j <= N; j++) {
            int pot = primes[i];
            dp[i][j] = dp[i - 1][j];
            while (pot <= j) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - pot] * pot) % M;
                pot *= primes[i];
            }
        }
    }

    cout << dp[primes.size() - 1][N] << "\n";
}