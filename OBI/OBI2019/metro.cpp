#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, m, pai[MAXN], dist[2][MAXN];
vector<int> tree[2][MAXN];

void dfs(int u, int p, int d, int q, int flag) {
    pai[u] = p;
    dist[q][u] = d;

    for (auto v : tree[flag][u]) {
        if (v == p) continue;
        dfs(v, u, d + 1, q, flag);
    }
}

int findCenter(int flag) {
    int size = (flag) ? m : n;

    dfs(1, -1, 0, 0, flag);

    int ponta1, ponta2, maior = 0;

    for (int i = 1; i <= size; i++) {
        if (dist[0][i] > maior) {
            maior = dist[0][i];
            ponta1 = i;
        }
    }

    dfs(ponta1, -1, 0, 0, flag);

    maior = 0;
    
    for (int i = 1; i <= size; i++) {
        if (dist[0][i] > maior) {
            maior = dist[0][i];
            ponta2 = i;
        }
    }

    dfs(ponta2, -1, 0, 1, flag);

    int u = ponta1, best = INT_MAX, center = u;

    while (u != -1) {
        if (max(dist[0][u], dist[1][u]) < best) {
            best = max(dist[0][u], dist[1][u]);
            center = u;
        }
        u = pai[u];
    }

    return center;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        tree[0][a].push_back(b);
        tree[0][b].push_back(a);
    }

    for (int i = 1; i < m; i++) {
        int a, b; cin >> a >> b;
        tree[1][a].push_back(b);
        tree[1][b].push_back(a);
    }

    cout << findCenter(0) << " " << findCenter(1) << "\n";
}