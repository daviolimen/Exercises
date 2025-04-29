/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: lamps
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<int> fState;
vector<vector<bool>> pos;

void doOp(vector<bool> &v, int op) {
    if (op == 0) {
        for (int i = 1; i <= N; i++) v[i] = !v[i];
    } else if (op == 1) {
        for (int i = 1; i <= N; i += 2) v[i] = !v[i];
    } else if (op == 2) {
        for (int i = 2; i <= N; i += 2) v[i] = !v[i];
    } else {
        for (int i = 1; i <= N; i += 3) v[i] = !v[i];
    }
}

void solve() {
    for (int mask = 0; mask < (1 << 4); mask++) {
        int cnt = __builtin_popcount(mask);
        if (cnt > C) continue;
        if (cnt % 2 != C % 2) continue;
        vector<bool> curr(N + 1, 1);
        for (int i = 0; i < 4; i++) {
            if (mask & (1 << i)) {
                doOp(curr, i);
            }
        }
        bool ok = 1;
        for (int i = 1; i <= N; i++) {
            if (fState[i] == -1) continue;
            if (curr[i] != fState[i]) {
                ok = 0;
                break;
            }
        }
        if (!ok) continue;
        pos.push_back(curr);
    }
}

int main() {
    ifstream cin ("lamps.in");
    ofstream cout ("lamps.out");
    cin >> N >> C;
    fState = vector<int>(N + 1, -1);
    while (true) {
        int x; cin >> x;
        if (x == -1) break;
        fState[x] = 1;
    }
    while (true) {
        int x; cin >> x;
        if (x == -1) break;
        fState[x] = 0;
    }

    solve();
    sort(pos.begin(), pos.end());
    for (auto v : pos) {
        for (int i = 1; i <= N; i++) cout << v[i];
        cout << "\n";
    }
    if (pos.empty()) cout << "IMPOSSIBLE\n";

    return 0;
}