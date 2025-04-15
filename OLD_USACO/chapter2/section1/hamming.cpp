/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: hamming
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int distHamm(int a, int b) {
    int res = 0;
    for (int i = 0; i < 8; i++) {
        bool x1 = a & (1 << i);
        bool x2 = b & (1 << i);
        if (x1 != x2) res++;
    }
    return res;
}

int main() {
    ifstream cin ("hamming.in");
    ofstream cout ("hamming.out");
    int n, b, d; cin >> n >> b >> d;
    int total = (1 << b);

    vector<int> ans;

    for (int i = 0; i < total; i++) {
        if (ans.size() == n) break;
        bool ok = 1;
        for (auto x : ans) {
            if (distHamm(i, x) < d) {
                ok = 0;
                break;
            }
        }
        if (!ok) continue;
        ans.push_back(i);
    }

    cout << ans[0];
    for (int i = 1; i < (int) ans.size(); i++) {
        cout << " \n"[i % 10 == 0] << ans[i];
    }

    cout << "\n";

    return 0;
}