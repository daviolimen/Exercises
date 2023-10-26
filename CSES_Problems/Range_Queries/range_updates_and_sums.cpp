#include <bits/stdc++.h>
using namespace std;

#define MAXN 200010

int arr[MAXN];
long long lz[4 * MAXN], tree[4 * MAXN];

void unlazy(int node, int tl, int tr, int op) {
    if (op == 1) tree[node] += (tr - tl + 1) * lz[node];
    else if (op == 2) tree[node] = (tr - tl + 1) * lz[node];

    if (tl != tr) {
        if (op == 1) {
            lz[2 * node] += lz[node];
            lz[2 * node + 1] += lz[node];
        } else if (op == 2) {
            lz[2 * node] = lz[node];
            lz[2 * node + 1] = lz[node];
        }
    }

    lz[node] = 0;
}

void build(int node, int tl, int tr) {
    if (tl == tr) {
        tree[node] = (long long) arr[tl];
        return;
    }

    int mid = (tl + tr) >> 1;

    build(2 * node, tl, mid);
    build(2 * node + 1, mid + 1, tr);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(int node, int tl, int tr, int l, int r, int x, int op) {
    unlazy(node, tl, tr, op);

    if ((tl > r) || (tr < l)) return;

    if ((l <= tl) && (tr <= r)) {
        lz[node] += x;
        unlazy(node, tl, tr, op);
        return;
    }

    int mid = (tl + tr) >> 1;

    update(2 * node, tl, mid, l, r, x, op);
    update(2 * node + 1, mid + 1, tr, l, r, x, op);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];


}