#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int arr[MAXN];
pair<int, int> tree[4 * MAXN];

void build(int node, int tl, int tr) {
    if (tl == tr) {
        tree[node] = {arr[tl], 1};
        return;
    }

    int mid = (tl + tr) >> 1;

    build(2 * node + 1, tl, mid);
    build(2 * node + 2, mid + 1, tr);

    if (tree[2 * node + 1].first == tree[2 * node + 2].first) tree[node] = {tree[2 * node + 1].first, tree[2 * node + 1].second + tree[2 * node + 2].second};
    else tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
}

void update(int node, int tl, int tr, int idx, int x) {
    if (tl == tr) {
        tree[node] = {x, 1};
        arr[idx] = x;
        return;
    }

    int mid = (tl + tr) >> 1;

    if ((tl <= idx) && (idx <= mid)) update(2 * node + 1, tl, mid, idx, x);
    else update(2 * node + 2, mid + 1, tr, idx, x);

    if (tree[2 * node + 1].first == tree[2 * node + 2].first) tree[node] = {tree[2 * node + 1].first, tree[2 * node + 1].second + tree[2 * node + 2].second};
    else tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
}

pair<int, int> query(int node, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l)) return {INT_MAX, 0};

    if ((l <= tl) && (tr <= r)) return tree[node];

    int mid = (tl + tr) >> 1;

    pair<int, int> q1 = query(2 * node + 1, tl, mid, l, r), q2 = query(2 * node + 2, mid + 1, tr, l, r);

    if (q1.first == q2.first) return {q1.first, q1.second + q2.second};
    else return min(q1, q2);
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
            int l, r; cin >> l >> r;
            pair<int, int> q = query(0, 0, n - 1, l, r - 1);
            cout << q.first << " " << q.second << "\n";
        }
    }
}