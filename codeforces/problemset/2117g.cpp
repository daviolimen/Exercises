#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200100;

int n, m, dist[2][MAXN];
vector<pair<int, int>> graph[MAXN];
bool visited[MAXN];

void dijkstra(int start, int flag) {
    dist[flag][start] = 0;
    for (int i = 1; i <= n; i++) visited[i] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(-1, start);

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = 1;

        for (auto [v, c] : graph[u]) {
            if (dist[flag][v] > max(dist[flag][u], c)) {
                dist[flag][v] = max(dist[flag][u], c);
                pq.emplace(dist[flag][v], v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            vector<pair<int, int>>().swap(graph[i]);
            dist[0][i] = dist[1][i] = INT_MAX;
        }

        vector<tuple<int, int, int>> edges;

        for (int i = 0; i < m; i++) {
            int a, b, c; cin >> a >> b >> c;
            edges.emplace_back(a, b, c);
            graph[a].emplace_back(b, c);
            graph[b].emplace_back(a, c);
        }

        dijkstra(1, 0);
        dijkstra(n, 1);

        int best = INT_MAX;
        for (int i = 0; i < m; i++) {
            auto [a, b, c] = edges[i];
            best = min(best, max({dist[0][a], dist[1][a], dist[1][b], dist[0][b]}) + c);
        }

        cout << best << "\n";
    }
}