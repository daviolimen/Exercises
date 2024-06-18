#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> ti;

const int MAXN = 100001;

int n, m, k, precos[MAXN];
map<int, int> dist[MAXN];
map<int, vector<int>> graph[MAXN];

int dijkstra(int start, int end) {
    dist[start][0] = 0;

    priority_queue<ti, vector<ti>, greater<ti>> heap;
    heap.emplace(0, start, 0);

    while (!heap.empty()) {
        auto [cost, u, tp] = heap.top();
        heap.pop();

        if (cost != dist[u][tp]) continue;



        if (tp == 0) {
            for (auto X : graph[u]) {
                int color = X.first;
                if ((dist[u].find(color) == dist[u].end()) || (dist[u][color] > dist[u][tp] + precos[color])) {
                    dist[u][color] = dist[u][tp] + precos[color];
                    heap.emplace(dist[u][color], u, color);
                }
            }
        } else {
            for (auto v : graph[u][tp]) {
                if ((dist[v].find(tp) == dist[v].end()) || (dist[v][tp] > dist[u][tp])) {
                    dist[v][tp] = dist[u][tp];
                    heap.emplace(dist[v][tp], v, tp);
                }
                if ((dist[v].find(0) == dist[v].end()) || (dist[v][0] > dist[u][tp])) {
                    dist[v][0] = dist[u][tp];
                    heap.emplace(dist[v][0], v, 0);
                }
            }
        }
    }

    if (dist[end].find(0) == dist[end].end()) return -1;
    return dist[end][0];
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) cin >> precos[i];
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a][c].push_back(b);
        graph[b][c].push_back(a);
    }
    int s, t; cin >> s >> t;
    cout << dijkstra(s, t) << "\n";
}