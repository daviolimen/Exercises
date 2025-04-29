/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: money
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll v, n, coins[30], dp[10100];

int main() {
    ifstream cin ("money.in");
    ofstream cout ("money.out");
    cin >> v >> n;
    for (int i = 0; i < v; i++) cin >> coins[i];
    dp[0] = 1;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j <= n; j++) {
            if (j - coins[i] < 0) continue;
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[n] << "\n";
    return 0;
}