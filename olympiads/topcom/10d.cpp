#include <bits/stdc++.h>
using namespace std;

int n, m, c, k, dist[250];
vector<vector<pair<int, int>>> graph;

void dijkstra(int start) {
    memset(dist, 0x3f3f3f3f, sizeof(dist));

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (dist[u] <= cost) continue;
        dist[u] = cost;

        for (auto [v, p] : graph[u]) {
            if (dist[v] > dist[u] + p) {
                pq.emplace(dist[u] + p, v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    while (true) {
        cin >> n >> m >> c >> k;
        graph = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            int u, v, w; cin >> u >> v >> w;
            if (v < c) swap(u, v);
            if (u < c) {
                if (v >= c) {
                    graph[v].emplace_back(u, w);
                } else {
                    if (u > v) swap(u, v);
                    if (v == u + 1) graph[u].emplace_back(v, w);
                }
            } else {
                graph[u].emplace_back(v, w);
                graph[v].emplace_back(u, w);
            }
        }

        dijkstra(k);
        cout << dist[c - 1] << "\n";
    }
}