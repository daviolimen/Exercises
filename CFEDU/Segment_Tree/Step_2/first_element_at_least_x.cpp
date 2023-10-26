#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int n, arr[MAXN], tree[4 * MAXN];

void build(int node, int tl, int tr) {
    if (tl == tr) {
        tree[node] = arr[tl];
        return;
    }

    int mid = (tl + tr) >> 1;

    build(2 * node + 1, tl, mid);
    build(2 * node + 2, mid + 1, tr);

    tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
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

    tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
}

int query(int node, int tl, int tr, int x) {
    if (tl == n) return -1;

    if ((tl == tr) && (arr[tl] >= x)) {
        return tl;
    }

    int mid = (tl + tr) >> 1;

    if (tree[2 * node + 1] >= x) return query(2 * node + 1, tl, mid, x);
    return query(2 * node + 2, mid + 1, tr, x);
}

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    build(0, 0, n - 1);

    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int i, v; cin >> i >> v;
            update(0, 0, n - 1, i, v);
        } else if (op == 2) {
            int x; cin >> x;
            cout << query(0, 0, n - 1, x) << "\n";
        }
    }
}