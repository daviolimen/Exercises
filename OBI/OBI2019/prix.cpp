#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int) 1e6 + 10;

struct Edge {int u, l, r;};

int n, m, aux, tree[MAXN], mark[MAXN];
Edge edges[MAXN];
vector<int> graph[MAXN];

void build(int node, int tl, int tr) {
    if (tl == tr) {
        tree[node] = ++aux;
        graph[tree[node]].push_back(tl);
        return;
    }

    int mid = (tl + tr) >> 1;

    build(2 * node, tl, mid);
    build(2 * node + 1, mid + 1, tr);

    tree[node] = ++aux;

    graph[tree[node]].push_back(tree[2 * node]);
    graph[tree[node]].push_back(tree[2 * node + 1]);
}

void addEdge(int node, int tl, int tr, int u, int l, int r) {
    if ((tl > r) || (tr < l)) return;

    if ((l <= tl) && (tr <= r)) {
        graph[u].push_back(tree[node]);
        return;
    }

    int mid = (tl + tr) >> 1;

    addEdge(2 * node, tl, mid, u, l, r);
    addEdge(2 * node + 1, mid + 1, tr, u, l, r);
}

bool dfs(int u) {
    mark[u] = 1;

    for (auto v : graph[u]) {
        if (mark[v] == 1) return true;
        if ((mark[v] == 0) && (dfs(v))) return true;
    }

    mark[u] = 2;
    return false;
}

bool ok(int x) {
    memset(mark, 0, sizeof(mark));

    for (int i = 1; i <= n; i++) graph[i].clear();

    for (int i = 1; i <= x; i++) addEdge(1, 1, n, edges[i].u, edges[i].l, edges[i].r);

    for (int i = 1; i <= n; i++) {
        if ((!mark[i]) && (dfs(i))) return true;
    }

    return false;
}

int busca() {
    int ini = 1, fim = m, meio, ans = -1;

    while (ini <= fim) {
        meio = (ini + fim) >> 1;

        if (ok(meio)) {
            ans = meio;
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }

    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> edges[i].u >> edges[i].l >> edges[i].r;

    aux = n;
    build(1, 1, n);

    cout << busca() << "\n";
}