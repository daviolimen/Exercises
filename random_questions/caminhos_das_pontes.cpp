#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

#define MAXN 1001
#define INF 10000001

int n, m, dist[MAXN];
bool visited[MAXN];
vector<pi> graph[MAXN];

void dijkstra(int start) {
    fill(dist, dist + n + 2, INF);
    dist[start] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    heap.emplace(0, start);

    while (!heap.empty()) {
        int u = heap.top().second;
        heap.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto V : graph[u]) {
            int v, w; tie(v, w) = V;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                heap.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int s, t, b;
    for (int i = 0; i < m; i++) {
        cin >> s >> t >> b;
        graph[s].emplace_back(t, b);
        graph[t].emplace_back(s, b);
    }
    dijkstra(0);
    cout << dist[n+1] << "\n";
}