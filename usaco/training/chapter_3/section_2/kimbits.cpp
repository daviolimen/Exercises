/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: kimbits
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

unsigned dp[32][32];

int main() {
    ifstream cin ("kimbits.in");
    ofstream cout ("kimbits.out");
    for (int i = 0; i < 32; i++) dp[i][0] = dp[0][i] = 1;
    for (int i = 1; i < 32; i++) {
        for (int j = 1; j < 32; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }

    unsigned N, L, I; cin >> N >> L >> I;
    I--;
    string ans;

    while (N > 0) {
        if (I >= dp[N - 1][L]) {
            ans.push_back('1');
            I -= dp[N - 1][L];
            N--;
            L--;
        } else {
            ans.push_back('0');
            N--;
        }
    }

    cout << ans << "\n";
    return 0;
}