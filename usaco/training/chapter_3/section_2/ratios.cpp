/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: ratios
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> inp;

vector<int> somar(int i, int j, int k) {
    vector<int> res{i * inp[1][0] + j * inp[2][0] + k * inp[3][0],
    i * inp[1][1] + j * inp[2][1] + k * inp[3][1],
    i * inp[1][2] + j * inp[2][2] + k * inp[3][2]};
    return res;
}

int main() {
    ifstream cin ("ratios.in");
    ofstream cout ("ratios.out");
    inp = vector<vector<int>>(4, vector<int>(3));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> inp[i][j];
        }
    }

    int bestSum = INT_MAX, bestI, bestJ, bestK, qnt = -1;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 100; k++) {
                if ((!i) && (!j) && (!k)) continue;
                auto v = somar(i, j, k);
                bool ok = 1;
                int divi = -1;
                for (int l = 0; l < 3; l++) {
                    if (inp[0][l] == 0) {
                        if (v[l] != 0) ok = 0;
                        continue;
                    }
                    if (v[l] % inp[0][l] != 0) {
                        ok = 0;
                        continue;
                    }
                    if (divi == -1) divi = v[l] / inp[0][l];
                    else {
                        if (v[l] / inp[0][l] != divi) {
                            ok = 0;
                            continue;
                        }
                    }
                }
                if (ok) {
                    if (i + j + k < bestSum) {
                        bestSum = i + j + k;
                        bestI = i;
                        bestJ = j;
                        bestK = k;
                        qnt = divi;
                    }
                }
            }
        }
    }

    if (qnt == -1) {
        cout << "NONE\n";
    } else {
        cout << bestI << " " << bestJ << " " << bestK << " " << qnt <<  "\n";
    }
    return 0;
}