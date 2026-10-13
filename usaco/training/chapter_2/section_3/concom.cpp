/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: concom
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;

int n, mat[MAXN][MAXN], dp[MAXN][MAXN][MAXN];
bool dono[MAXN][MAXN];
bitset<MAXN> aux[MAXN][MAXN];

int main() {
    ifstream cin ("concom.in");
    ofstream cout ("concom.out");
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        mat[a][b] = c;
    }

    for (int i = 1; i <= 100; i++) dono[i][i] = 1;

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            for (int k = 1; k <= 100; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                int bestL = -1;
                for (int l = 1; l <= 100; l++) {
                    if (!dono[j][l]) continue;
                    if (aux[j][k][l]) continue;
                    if (dp[i][j][k] < dp[i - 1][j][k] + mat[l][k]) {
                        dp[i][j][k] = dp[i - 1][j][k] + mat[l][k];
                        bestL = l;
                    }
                }
                if (dp[i][j][k] > 50) dono[j][k] = 1;
                if (bestL == -1) continue;
                aux[j][k][bestL] = 1;
            }
        }
    }

    vector<pair<int, int>> ans;

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (i == j) continue;
            if (dono[i][j]) ans.emplace_back(i, j);
        }
    }

    for (auto p : ans) cout << p.first << " " << p.second << "\n";
    return 0;
}