#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int n, arr[MAXN], tree[4 * MAXN];

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = arr[l];
        return;
    }

    int mid = (l + r) >> 1;

    build(2 * node + 1, l, mid);
    build(2 * node + 2, mid + 1, r);

    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
}

void update(int node, int tl, int tr, int idx, int x) {
    if (tl == tr) {
        tree[node] = x;
        arr[idx] = x;
        return;
    }

    int mid = (tl + tr) >> 1;

    if ((tl <= idx) && (idx <= mid)) update(2 * node + 1, tl, mid, idx, x);
    else update(2 * node + 2, mid + 1, tr, idx, x);

    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
}

int query(int node, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l)) return INT_MAX;

    if ((l <= tl) && (tr <= r)) return tree[node];

    int mid = (tl + tr) >> 1;

    return (min(query(2 * node + 1, tl, mid, l, r), query(2 * node + 2, mid + 1, tr, l, r)));
}

int main() {
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> arr[i];

    build(0, 0, n - 1);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int k, u; cin >> k >> u; k--;
            update(0, 0, n - 1, k, u);
        } else if (t == 2) {
            int a, b; cin >> a >> b; a--; b--;
            cout << query(0, 0, n - 1, a, b) << "\n";
        }
    }
}