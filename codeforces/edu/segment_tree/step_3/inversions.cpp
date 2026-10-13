// BIT - 31ms
// Segment Tree - 46ms

#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int tree[4 * MAXN];

void update(int node, int tl, int tr, int idx) {
    if (tl == tr) {
        tree[node]++;
        return;
    }

    int mid = (tl + tr) >> 1;

    if ((tl <= idx) && (idx <= mid)) update(2 * node + 1, tl, mid, idx);
    else update(2 * node + 2, mid + 1, tr, idx);

    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

int query(int node, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l)) return 0;

    if ((l <= tl) && (tr <= r)) return tree[node];

    int mid = (tl + tr) >> 1;

    return (query(2 * node + 1, tl, mid, l, r) + query(2 * node + 2, mid + 1, tr, l, r));
}

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int invs[MAXN];
    for (int i = 0; i < n; i++) {
        int a; cin >> a; a--;
        update(0, 0, n - 1, a);
        invs[i] = query(0, 0, n - 1, a + 1, n - 1);
    }

    for (int i = 0; i < n; i++) {
        cout << invs[i] << " \n"[i == n - 1];
    }
}