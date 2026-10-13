/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: comehome
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int P, mat[100][100];

int main() {
    ifstream cin ("comehome.in");
    ofstream cout ("comehome.out");
    map<char, int> mp;
    for (int i = 0; i < 26; i++) mp['a' + i] = i;
    for (int i = 0; i < 26; i++) mp['A' + i] = i + 26;
    cin >> P;
    memset(mat, 0x3f3f3f3f, sizeof(mat));
    for (int i = 0; i < P; i++) {
        char a, b; int c; cin >> a >> b >> c;
        int na = mp[a];
        int nb = mp[b];
        mat[na][nb] = min(mat[na][nb], c);
        mat[nb][na] = min(mat[nb][na], c);
    }

    int floyd[100][100];
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            if (i == j) floyd[i][j] = 0;
            else if (mat[i][j]) floyd[i][j] = mat[i][j];
            else floyd[i][j] = (int) 1e7;
        }
    }

    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            for (int k = 0; k < 52; k++) {
                floyd[j][k] = min(floyd[j][k], floyd[j][i] + floyd[i][k]);
            }
        }
    }

    int best = (int) 1e7, bestNode = -1;
    for (int i = 26; i < 51; i++) {
        if (floyd[i][51] < best) {
            best = floyd[i][51];
            bestNode = i;
        }
    }

    cout << (char) ('A' + (bestNode - 26)) << " " << best << "\n";

    return 0;
}