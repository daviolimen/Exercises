#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int arr[MAXN], tree[4 * MAXN];

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

int query(int node, int tl, int tr, int x, int l) {
    if (tl == tr) {
        if ((tl >= l) && (arr[tl] >= x)) return tl;
        return -1;
    }

    int mid = (tl + tr) >> 1, ans;

    if ((tree[2 * node + 1] >= x) && (mid >= l)) {
        ans = query(2 * node + 1, tl, mid, x, l);
        if (ans != -1) return ans;
    }
    return query(2 * node + 2, mid + 1, tr, x, l);
}

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    build(0, 0, n - 1);

    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int i, v; cin >> i >> v;
            update(0, 0, n - 1, i, v);
        } else if (op == 2) {
            int x, l; cin >> x >> l;
            cout << query(0, 0, n - 1, x, l) << "\n";
        }
    }
}
