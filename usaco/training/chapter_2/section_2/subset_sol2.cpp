/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: subset
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin ("subset.in");
    ofstream cout ("subset.out");

    int n; cin >> n;
    int soma = n * (n + 1);
    if (soma % 4) {
        cout << "0\n";
        return 0;
    }
    soma /= 4;
    vector<long long> dp(1000);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = soma; j >= 1; j--) {
            if (j - i < 0) continue;
            dp[j] += dp[j - i];
        }
    }

    cout << dp[soma] / 2 << "\n";
    return 0;
}