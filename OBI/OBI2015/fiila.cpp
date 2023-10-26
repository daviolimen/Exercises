#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int arr[MAXN], tree[4 * MAXN];

void build(int node, int tl, int tr) {
    if (tl == tr) {
        tree[node] = arr[tl];
        return;
    }

    int mid = (tl + tr) >> 1;

    build(2 * node, tl, mid);
    build(2 * node + 1, mid + 1, tr);

    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int tl, int tr, int idx, int x) {
    if (tree[node] <= x) return 0;

    if (tl > idx) return 0;

    if (tl == tr) return tl;

    int mid = (tl + tr) >> 1;

    if (tr > idx) return max(query(2 * node, tl, mid, idx, x), query(2 * node + 1, mid + 1, tr, idx, x));

    if (tree[2 * node + 1] > x) return query(2 * node + 1, mid + 1, tr, idx, x);

    return query(2 * node, tl, mid, idx, x);
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    build(1, 1, n);

    int q; cin >> q;
    
    while (q--) {
        int t, i, x; cin >> t >> i >> x;

        if (t == 0) {
            
        } else if (t == 1) {
            cout << query(1, 1, n, i, arr[i] + x) << "\n";
        }
    }
}