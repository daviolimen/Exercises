/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: nocows
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

#define MOD 9901

int dp[200][100];

int solve(int n, int k) {
    if (n < 0) return 0;
    if (k < 0) return 0;
    if (n == 0) return 1;
    if (n > 0 && k == 0) return 0;
    if (dp[n][k] != -1) return dp[n][k];
    int res = 0;
    res += 2 * solve(n - 2, k - 1);
    for (int i = 2; i < n; i += 2) {
        res += solve(i - 2, k - 1) * solve(n - i - 2, k - 1);
        res %= MOD;
    }
    res = (res + MOD) % MOD;
    return dp[n][k] = res;
}

int main() {
    ifstream cin ("nocows.in");
    ofstream cout ("nocows.out");
    memset(dp, -1, sizeof(dp));
    int n, k; cin >> n >> k;
    cout << (((solve(n - 3, k - 2) - solve(n - 3, k - 3) + MOD)) % MOD) << "\n";
}