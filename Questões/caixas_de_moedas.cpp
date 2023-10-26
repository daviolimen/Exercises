#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int arr[MAXN], lz[4 * MAXN], tree[4 * MAXN];

void unlazy(int node, int tl, int tr) {
    if (lz[node] == -1) return;

    tree[node] = (tr - tl + 1) * lz[node];

    if (tl != tr) {
        lz[2 * node + 1] = lz[node];
        lz[2 * node + 2] = lz[node];
    }

    lz[node] = -1;
}

void update(int node, int tl, int tr, int l, int r, int v) {
    unlazy(node, tl, tr);

    if ((tl > r) || (tr < l)) return;

    if ((l <= tl) && (tr <= r)) {
        lz[node] = v;
        unlazy(node, tl, tr);
        return;
    }

    int mid = (tl + tr) >> 1;

    update(2 * node + 1, tl, mid, l, r, v);
    update(2 * node + 2, mid + 1, tr, l, r, v);

    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

int query(int node, int tl, int tr, int l, int r) {
    unlazy(node, tl, tr);

    if ((tl > r) || (tr < l)) return 0;

    if ((l <= tl) && (tr <= r)) return tree[node];

    int mid = (tl + tr) >> 1;

    return (query(2 * node + 1, tl, mid, l, r) + query(2 * node + 2, mid + 1, tr, l, r));
}

int main() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        update(0, 0, n - 1, i, i, a);
    }

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int a, b, k; cin >> a >> b >> k; a--; b--;
            update(0, 0, n - 1, a, b, k);
        } else if (op == 2) {
            int a, b; cin >> a >> b; a--; b--;
            cout << query(0, 0, n - 1, a, b) << "\n";
        }
    }
}