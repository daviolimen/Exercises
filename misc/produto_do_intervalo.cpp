#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int arr[MAXN], tree[4 * MAXN];

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = arr[l];
        return;
    }

    int mid = (l + r) >> 1;

    build(2 * node + 1, l, mid);
    build(2 * node + 2, mid + 1, r);

    tree[node] = tree[2 * node + 1] * tree[2 * node + 2];
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

    tree[node] = tree[2 * node + 1] * tree[2 * node + 2];
}

int query(int node, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l)) return 1;

    if ((l <= tl) && (tr <= r)) return tree[node];

    int mid = (tl + tr) >> 1;

    return (query(2 * node + 1, tl, mid, l, r) * query(2 * node + 2, mid + 1, tr, l, r));
}

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    fill_n(tree, 4 * MAXN, 1);
    fill_n(arr, MAXN, 1);

    int n, k;
    while (cin >> n >> k) {
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a > 0) arr[i] = 1;
            else if (a < 0) arr[i] = -1;
            else arr[i] = 0;
        }

        build(0, 0, n - 1);

        while (k--) {
            char op; cin >> op;
            if (op == 'C') {
                int i, v; cin >> i >> v; i--;
                if (v > 0) v = 1;
                else if (v < 0) v = -1;
                else v = 0;
                update(0, 0, n - 1, i, v);
            } else if (op == 'P') {
                int i, j; cin >> i >> j; i--; j--;
                int ans = query(0, 0, n - 1, i, j);
                if (ans == 1) cout << "+";
                else if (ans == 0) cout << "0";
                else if (ans == -1) cout << "-";
            }
        }
        cout << "\n";
    }
}