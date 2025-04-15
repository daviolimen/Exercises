/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: combo
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

vector<int> findDigs(int x) {
    vector<int> res;
    while (x > 0) {
        res.push_back(x % 10);
        x /= 10;
    }
    return res;
}

int main() {
    ifstream cin ("combo.in");
    ofstream cout ("combo.out");

    int n; cin >> n;
    vector<vector<int>> combos(2, vector<int>(3));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> combos[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                vector<int> sol({i, j, k});
                bool novaSol = 0;
                for (int l = 0; l < 2; l++) {
                    bool ok = 1;
                    for (int a = 0; a < 3; a++) {
                        int diff = abs(sol[a] - combos[l][a]);
                        if ((diff <= 2) || (diff >= n - 2)) continue;
                        ok = 0;
                        break;
                    }
                    if (ok) novaSol = 1;
                }
                if (novaSol) ans++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}