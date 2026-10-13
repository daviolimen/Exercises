/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: holstein
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin ("holstein.in");
    ofstream cout ("holstein.out");
    int v, g;
    cin >> v;
    vector<int> vita(v);
    for (int i = 0; i < v; i++) cin >> vita[i];
    cin >> g;
    vector<vector<int>> feed(g, vector<int>(v));
    for (int i = 0; i < g; i++) {
        for (int j = 0; j < v; j++) {
            cin >> feed[i][j];
        }
    }

    int bestMask = -1, bestAmount = INT_MAX, bestSum = INT_MAX;

    for (int mask = 1; mask < (1 << g); mask++) {
        int idxSoma = 0;
        vector<int> soma(v);
        for (int i = 0; i < g; i++) {
            if (!(mask & (1 << i))) continue;
            idxSoma += i;
            for (int j = 0; j < v; j++) soma[j] += feed[i][j];
        }
        bool ok = 1;
        for (int i = 0; i < v; i++) {
            if (soma[i] < vita[i]) {
                ok = 0;
                break;
            }
        }
        if (!ok) continue;
        int curr = __builtin_popcount(mask);
        if (curr == bestAmount) {
            if (idxSoma < bestSum) {
                bestMask = mask;
                bestSum = idxSoma;
                bestAmount = curr;
            }
        }
        if (curr < bestAmount) {
            bestMask = mask;
            bestAmount = curr;
            bestSum = idxSoma;
        }
    }

    cout << bestAmount;
    for (int i = 0; i < g; i++) if (bestMask & (1 << i)) cout << " " << i + 1;
    cout << "\n";
    return 0;
}