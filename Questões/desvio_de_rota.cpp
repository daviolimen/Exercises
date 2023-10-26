#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

#define MAXN 250

int n, m, c, k;
vector<pi> graph[MAXN];
bool visited[MAXN];

int dijkstra(int start, int end) {
    memset(visited, 0, sizeof(visited));
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    heap.emplace(0, start);

    while (!heap.empty()) {
        int cost, u; tie(cost, u) = heap.top();
        heap.pop();

        if (visited[u]) continue;
        visited[u] = true;

        if (u == end) return cost;

        for (auto V : graph[u]) {
            int v, w; tie(v, w) = V;
            if (visited[v]) continue;
            heap.emplace(cost + w, v);
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> c >> k;
    while (n != 0) {
        for (int i = 0; i < n; i++) graph[i].clear();
        int u, v, p;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> p;
            if ((u >= c) && (v >= c)) {
                graph[u].emplace_back(v, p);
                graph[v].emplace_back(u, p);
            }
            if ((u < c) && (v < c) && abs(u - v) == 1) {
                graph[u].emplace_back(v, p);
                graph[v].emplace_back(u, p);
            }
            if ((u >= c) && (v < c)) graph[u].emplace_back(v, p);
            if ((v >= c) && (u < c)) graph[v].emplace_back(u, p);
        }
        cout << dijkstra(k, c - 1) << "\n";
        cin >> n >> m >> c >> k;
    }
}