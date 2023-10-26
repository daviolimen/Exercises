#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

struct Node {
    int mini, maxi, ans;
};

Node join(Node const& a, Node const& b) {
    return {min(a.mini, b.mini), max(a.maxi, b.maxi), max({a.ans, b.ans, (a.maxi - b.mini), (b.maxi - a.mini)})};
}

int arr[MAXN];
Node tree[4 * MAXN];

void build(int node, int tl, int tr) {
    if (tl == tr) {
        tree[node].mini = tree[node].maxi = arr[tl];
        return;
    }

    int mid = (tl + tr) >> 1;

    build(2 * node + 1, tl, mid);
    build(2 * node + 2, mid + 1, tr);

    tree[node] = join(tree[2 * node + 1], tree[2 * node + 2]);
}

void update(int node, int tl, int tr, int idx, int x) {
    if (tl == tr) {
        tree[node].maxi = max(tree[node].maxi, x);
        tree[node].mini = min(tree[node].mini, x);
        return;
    }

    int mid = (tl + tr) >> 1;

    if ((tl <= idx) && (idx <= mid)) update(2 * node + 1, tl, mid, idx, x);
    else update(2 * node + 2, mid + 1, tr, idx, x);

    tree[node] = join(tree[2 * node + 1], tree[2 * node + 2]);
}

Node query(int node, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l)) return {INT_MAX, 0, 0};

    if ((l <= tl) && (tr <= r)) return tree[node];

    int mid = (tl + tr) >> 1;

    return join(query(2 * node + 1, tl, mid, l, r), query(2 * node + 2, mid + 1, tr, l, r));
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    build(0, 0, n - 1);

    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int idx, x; cin >> x >> idx; idx--;
            update(0, 0, n - 1, idx, x);
        } else if (op == 2) {
            int l, r; cin >> l >> r; l--; r--;
            cout << query(0, 0, n - 1, l, r).ans << "\n";
        }
    }
}