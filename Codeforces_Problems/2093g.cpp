#include <bits/stdc++.h>
using namespace std;

struct Vertex {
    int maxIdx, prox[2];
    Vertex() {
        maxIdx = -1;
        memset(prox, -1, sizeof(prox));
    }
};

vector<Vertex> trie;

void addNum(int num, int idx) {
    int v = 0;
    trie[v].maxIdx = max(trie[v].maxIdx, idx);
    for (int i = 29; i >= 0; i--) {
        int iBit = (num >> i) & 1;
        if (trie[v].prox[iBit] == -1) {
            trie[v].prox[iBit] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].prox[iBit];
        trie[v].maxIdx = max(trie[v].maxIdx, idx);
    }
}

int find(int num, int lim) {
    int res = -1;
    int v = 0;
    bool ok = 1;
    for (int i = 29; i >= 0; i--) {
        int xBit = (num >> i) & 1;
        int kBit = (lim >> i) & 1;
        auto& prox = trie[v].prox;
        if (kBit == 1) {
            if (prox[xBit ^ 1] == -1) {
                ok = 0;
                break;
            }
            v = prox[xBit ^ 1];
        } else {
            if (prox[xBit ^ 1] != -1) {
                res = max(res, trie[prox[xBit ^ 1]].maxIdx);
            }
            if (prox[xBit ^ 0] == -1) {
                ok = 0;
                break;
            }
            v = prox[xBit ^ 0];
        }
    }

    if (ok) res = max(res, trie[v].maxIdx);
    return res;
}

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        int ans = n + 1;
        trie = vector<Vertex>(1);
        for (int i = 0; i < n; i++) {
            addNum(a[i], i);
            int cur = find(a[i], k);
            if (cur == -1) continue;
            ans = min(ans, i - cur + 1);
        }

        if (ans == n + 1) cout << "-1\n";
        else cout << ans << "\n";
    }
}