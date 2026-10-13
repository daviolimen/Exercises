#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000, INFMIN = -1e9 - 10;

struct no {
    int soma, bsum, pref, suff;
};

no join(const no& a, const no& b) {
    no res;
    res.soma = a.soma + b.soma;
    res.bsum = max({a.bsum, b.bsum, a.suff + b.pref});
    res.pref = max({a.pref, a.soma, a.soma + b.pref});
    res.suff = max({b.suff, b.soma, a.suff + b.soma});
    return res;
}

int arr[MAXN];
no tree[4 * MAXN];

void build(int node, int tl, int tr) {
    if (tl == tr) {
        tree[node].soma = tree[node].bsum = tree[node].pref = tree[node].suff = arr[tl];
        return;
    }

    int mid = (tl + tr) >> 1;

    build(2 * node + 1, tl, mid);
    build(2 * node + 2, mid + 1, tr);

    tree[node] = join(tree[2 * node + 1], tree[2 * node + 2]);
}

no query(int node, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l)) return {INFMIN, INFMIN, INFMIN, INFMIN};

    if ((l <= tl) && (tr <= r)) return tree[node];

    int mid = (tl + tr) >> 1;

    return join(query(2 * node + 1, tl, mid, l, r), query(2 * node + 2, mid + 1, tr, l, r));
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];

        build(0, 0, n - 1);

        int q; cin >> q;
        while (q--) {
            int a, b; cin >> a >> b; a--, b--;
            cout << query(0, 0, n - 1, a, b).bsum << "\n";
        }
    }
}