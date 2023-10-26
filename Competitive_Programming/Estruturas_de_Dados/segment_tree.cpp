#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, arr[MAXN], tree[4 * MAXN];

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = arr[l];
        return;
    }

    int mid = (l + r) >> 1;

    build(2 * node + 1, l, mid);
    build(2 * node + 2, mid + 1, r);

    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
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

    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];

}

int query(int node, int tl, int tr, int l, int r) {
    if ((r < tl) || (l > tr)) return 0;

    if ((tl >= l) && (tr <= r)) return tree[node];

    int mid = (tl + tr) >> 1;

    return (query(2 * node + 1, tl, mid, l, r) + query(2 * node + 2, mid + 1, tr, l, r));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    build(1, 0, n - 1);

    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int k, x; cin >> k >> x;
            update(1, 0, n - 1, k, x);
        } else if (t == 2) {
            int l, r; cin >> l >> r;
            cout << query(1, 0, n - 1, l, r) << "\n";
        }
    }
}