#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100100;

int N, Q, timer, tin[MAXN], tout[MAXN], pai[MAXN], idxToV[MAXN], t[4 * MAXN];
vector<int> trav, graph[MAXN];
bool modded[MAXN], marked[4 * MAXN];

void push(int v) {
    if (marked[v]) {
        t[v*2] = t[v*2+1] = t[v];
        marked[v*2] = marked[v*2+1] = true;
        marked[v] = false;
    }
}

void update(int v, int tl, int tr, int l, int r, int new_val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] = new_val;
        marked[v] = true;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm) 
        return get(v*2, tl, tm, pos);
    else
        return get(v*2+1, tm+1, tr, pos);
}

void dfs(int u, int p) {
    tin[u] = timer;
    idxToV[timer] = u;
    timer++;
    trav.push_back(u);
    for (auto v : graph[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    tout[u] = timer;
}

int query(int v, int k) {
    while (k--) v = get(1, 1, N, tin[v]);
}

void updateLegal(int v) {
    update(1, 1, N, tin[v] + 1, tout[v] - 1, v);
}

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    pai[1] = 1;
    for (int i = 2; i <= N; i++) {
        cin >> pai[i];
        graph[pai[i]].push_back(i);
    }

    dfs(1, 1);

    cin >> Q;
    while (Q--) {
        int op; cin >> op;
        if (op == 1) {
            int v, k; cin >> v >> k;
            cout << query(v, k) << "\n";
        } else if (op == 2) {
            int v; cin >> v;
            updateLegal(v);
        } else {
            cout << "Deu ruim.\n";
        }
    }
}