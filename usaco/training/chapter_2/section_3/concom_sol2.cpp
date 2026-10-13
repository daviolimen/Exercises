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

int owns[MAXN][MAXN], controls[MAXN][MAXN];

void addControl(int i, int j) {
    if (controls[i][j]) return;

    controls[i][j] = 1;

    for (int k = 1; k < MAXN; k++) {
        owns[i][k] += owns[j][k];
    }

    for (int k = 1; k < MAXN; k++) {
        if (controls[k][i]) addControl(k, j);
    }

    for (int k = 1; k < MAXN; k++) {
        if (owns[i][k] > 50) addControl(i, k);
    }
}

void addOwner(int i, int j, int p) {

    for (int k = 1; k < MAXN; k++) {
        if (controls[k][i]) owns[k][j] += p;
    }

    for (int k = 1; k < MAXN; k++) {
        if (owns[k][j] > 50) addControl(k, j);
    }
}

int main() {
    ifstream cin ("concom.in");
    ofstream cout ("concom.out");
    for (int i = 1; i <= 100; i++) controls[i][i] = 1;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        addOwner(a, b, c);
    }


    vector<pair<int, int>> ans;
    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j < MAXN; j++) {
            if (i == j) continue;
            if (controls[i][j]) ans.emplace_back(i, j);
        }
    }

    for (auto p : ans) cout << p.first << " " << p.second << "\n";
    return 0;
}