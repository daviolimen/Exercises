#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 100000

struct no {
    ll pre = 0, suf = 0, mx = 0, sum = 0;
};

int arr[MAXN];
no tree[4 * MAXN];

void build(int node, int tl, int tr) {
    if (tl == tr) {
        tree[node].sum = arr[tl];
        tree[node].pre = tree[node].suf = tree[node].mx = max(0, arr[tl]);
        return;
    }

    int mid = (tl + tr) >> 1;

    build(2 * node + 1, tl, mid);
    build(2 * node + 2, mid + 1, tr);

    tree[node].sum = tree[2 * node + 1].sum + tree[2 * node + 2].sum;
    tree[node].pre = max(tree[2 * node + 1].pre, tree[2 * node + 1].sum + tree[2 * node + 2].pre);
    tree[node].suf = max(tree[2 * node + 2].suf, tree[2 * node + 2].sum + tree[2 * node + 1].suf);
    tree[node].mx = max(tree[2 * node + 1].suf + tree[2 * node + 2].pre, max(tree[2 * node + 1].mx, tree[2 * node + 2].mx));
}

void update(int node, int tl, int tr, int idx, int x) {
    if (tl == tr) {
        arr[idx] = x;
        tree[node].sum = x;
        tree[node].pre = tree[node].suf = tree[node].mx = max(0, x);
        return;
    }

    int mid = (tl + tr) >> 1;

    if ((tl <= idx) && (idx <= mid)) update(2 * node + 1, tl, mid, idx, x);
    else update(2 * node + 2, mid + 1, tr, idx, x);

    tree[node].sum = tree[2 * node + 1].sum + tree[2 * node + 2].sum;
    tree[node].pre = max(tree[2 * node + 1].pre, tree[2 * node + 1].sum + tree[2 * node + 2].pre);
    tree[node].suf = max(tree[2 * node + 2].suf, tree[2 * node + 2].sum + tree[2 * node + 1].suf);
    tree[node].mx = max(tree[2 * node + 1].suf + tree[2 * node + 2].pre, max(tree[2 * node + 1].mx, tree[2 * node + 2].mx));
}

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    build(0, 0, n - 1);

    cout << tree[0].mx << "\n";

    while (m--) {
        int i, v; cin >> i >> v;
        update(0, 0, n - 1, i, v);
        cout << tree[0].mx << "\n";
    }
}