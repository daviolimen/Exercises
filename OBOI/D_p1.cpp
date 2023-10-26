#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
const int MAXN = 1001, MAXK = 500, INF = (int) 1e9;

int N, M, K, atr[MAXK], dist[MAXK][MAXN];
vector<pi> graph[MAXN];
bool visited[MAXN];

void dijkstra(int x) {
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < 1001; i++) dist[x][i] = INF;
    dist[x][atr[x]] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> heap;
    heap.emplace(0, atr[x]);

    while (!heap.empty()) {
        int u = heap.top().second;
        heap.pop();


        if (visited[u]) continue;
        visited[u] = true;

        for (auto [v, c] : graph[u]) {
            if (dist[x][v] > dist[x][u] + c) {
                dist[x][v] = dist[x][u] + c;
                heap.emplace(dist[x][v], v);
            }
        }
    }
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) cin >> atr[i];
    for (int i = 0; i < M; i++) {
        int u, v, p; cin >> u >> v >> p;
        graph[u].emplace_back(v, p);
        graph[v].emplace_back(u, p);
    }

    for (int i = 0; i < K; i++) dijkstra(i);

    int ans = INF;

    for (int i = 0; i < K; i++) {
        for (int j = i + 1; j < K; j++) ans = min(ans, dist[i][atr[j]]);
    }

    cout << ans << "\n";
}