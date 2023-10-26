#include <bits/stdc++.h>
using namespace std;

#define MAXN 101

int pai[MAXN], peso[MAXN], dist[MAXN];
vector<pair<int, int>> graph[MAXN];

int find(int x) {
    if (pai[x] == x) return x;

    return pai[x] = find(pai[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (peso[x] < peso[y]) pai[x] = y;
    else if (peso[y] < peso[x]) pai[y] = x;
    else {
        pai[y] = x;
        peso[x]++;
    }
}

void dfs(int u, int p) {
    for (auto [v, c] : graph[u]) {
        if (v == p) continue;
        dist[v] = min(dist[u], c);
        dfs(v, u);
    }
}

int main() {
    int n, m, tt = 1;
    while ((cin >> n >> m) && (n > 0) && (m > 0)) {
        for (int i = 1; i <= n; i++) {
            pai[i] = i;
            peso[i] = 0;
            dist[i] = 0;
            graph[i].clear();
        }

        vector<tuple<int, int, int>> edgeList(m);

        for (auto &[p, x, y] : edgeList) {
            cin >> x >> y >> p;
            p--;
        }

        sort(edgeList.begin(), edgeList.end(), greater());

        for (auto [p, x, y] : edgeList) {
            if (find(x) == find(y)) continue;
            join(x, y);
            graph[x].emplace_back(y, p);
            graph[y].emplace_back(x, p);
        }

        int S, D, T;
        cin >> S >> D >> T;

        dist[S] = T;
        dfs(S, 0);

        cout << "Scenario #" << tt++ << "\n";
        cout << "Minimum Number of Trips = " << ((T + dist[D] - 1) / dist[D]) << "\n";
        cout << "\n";
    }
}