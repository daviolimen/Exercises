#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;

#define MAXN 100001

int n, m, k, precos[MAXN];
vector<pi> graph[MAXN];
bool visited[MAXN];

int dijkstra(int start, int end) {
    memset(visited, 0, sizeof(visited));

    priority_queue<ti, vector<ti>, greater<ti>> heap;
    heap.emplace(0, 0, start);

    while (!heap.empty()) {
        auto [cost, type, u] = heap.top();
        heap.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto [v, ])
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) cin >> precos[i];
    for (int i = 1; i <= m; i++) {
        int v, u, t; cin >> v >> u >> t;
        graph[v].emplace_back(u, t);
        graph[u].emplace_back(v, t);
    }
    int a, b; cin >> a >> b;

    cout << dijkstra(a, b) << "\n";
}