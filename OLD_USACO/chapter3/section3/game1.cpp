/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: game1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;

int n, arr[MAXN], pref[MAXN], dp[MAXN][MAXN];

int main() {
    ifstream cin ("game1.in");
    ofstream cout ("game1.out");
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pref[i] = pref[i - 1] + arr[i];
        dp[i][i] = arr[i];
    }

    for (int sz = 2; sz <= n; sz++) {
        for (int i = sz; i <= n; i++) {
            int soma = pref[i] - pref[i - sz];
            dp[i - sz + 1][i] = max(soma - dp[i - sz + 2][i], soma - dp[i - sz + 1][i - 1]);
        }
    }
    cout << dp[1][n] << " " <<  pref[n] - dp[1][n] << "\n";
    return 0;
}