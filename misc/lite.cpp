#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

struct no {
    int zeros, ones;
};

int arr[MAXN];
bool lz[4 * MAXN];
no tree[4 * MAXN];

void build(int node, int tl, int tr) {
    if (tl == tr) {
        tree[node].zeros = 1;
        tree[node].ones = 0;
        return;
    }

    int mid = (tl + tr) >> 1;

    build(2 * node + 1, tl, mid);
    build(2 * node + 2, mid + 1, tr);

    tree[node].ones = tree[2 * node + 1].ones + tree[2 * node + 2].ones;
    tree[node].zeros = tree[2 * node + 1].zeros + tree[2 * node + 2].zeros;
}

void unlazy(int node, int tl, int tr) {
    if (lz[node] == 0) return;

    swap(tree[node].zeros, tree[node].ones);

    if (tl != tr) {
        lz[2 * node + 1] = !lz[2 * node + 1];
        lz[2 * node + 2] = !lz[2 * node + 2];
    }
    
    lz[node] = 0;
}

void update(int node, int tl, int tr, int l, int r) {
    unlazy(node, tl, tr);

    if ((tl > r) || (tr < l)) return;

    if ((l <= tl) && (tr <= r)) {
        lz[node] = !lz[node];
        unlazy(node, tl, tr);
        return;
    }

    int mid = (tl + tr) >> 1;

    update(2 * node + 1, tl, mid, l, r);
    update(2 * node + 2, mid + 1, tr, l, r);

    tree[node].ones = tree[2 * node + 1].ones + tree[2 * node + 2].ones;
    tree[node].zeros = tree[2 * node + 1].zeros + tree[2 * node + 2].zeros;
}

int query(int node, int tl, int tr, int l, int r) {
    unlazy(node, tl, tr);

    if ((tl > r) || (tr < l)) return 0;

    if ((l <= tl) && (tr <= r)) return tree[node].ones;

    int mid = (tl + tr) >> 1;

    return (query(2 * node + 1, tl, mid, l, r) + query(2 * node + 2, mid + 1, tr, l, r));
}

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;

    build(0, 0, n - 1);

    while (m--) {
        int op; cin >> op;
        if (op == 0) {
            int s, e; cin >> s >> e; s--; e--;
            update(0, 0, n - 1, s, e);
        } else if (op == 1) {
            int s, e; cin >> s >> e; s--; e--;
            cout << query(0, 0, n - 1, s, e) << "\n";
        }
    }

}