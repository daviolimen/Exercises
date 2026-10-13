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

    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

void update(int node, int tl, int tr, int idx) {
    if (tl == tr) {
        arr[idx] = !arr[idx];
        tree[node] = !tree[node];
        return;
    }

    int mid = (tl + tr) >> 1;

    if ((tl <= idx) && (idx <= mid)) update(2 * node + 1, tl, mid, idx);
    else update(2 * node + 2, mid + 1, tr, idx);

    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

int query(int node, int tl, int tr, int k) {
    if (tl == tr) {
        return tl;
    }

    int mid = (tl + tr) >> 1;

    if (tree[2 * node + 1] >= k + 1) return query(2 * node + 1, tl, mid, k);
    return query(2 * node + 2, mid + 1, tr, k - tree[2 * node + 1]);
}

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    build(0, 0, n - 1);

    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int i; cin >> i;
            update(0, 0, n - 1, i);
        } else if (op == 2) {
            int k; cin >> k;
            cout << query(0, 0, n - 1, k) << "\n";
        }
    }
}