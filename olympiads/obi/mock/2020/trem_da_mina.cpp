#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10010;

bool visited[MAXN], inCycle[MAXN];
int N, M, dist[MAXN];
pair<int, int> pai[MAXN];
vector<int> tamanhos;
vector<vector<int>> cycles;
vector<pair<int, int>> graph[MAXN];

void dfs(int u, int p, int cost) {
    if (visited[u]) {
        if (inCycle[u]) return;
        cycles.push_back({});
        int cur = p, tam = cost;
        while (cur != u) {
            inCycle[cur] = 1;
            cycles.back().push_back(cur);
            tam += pai[cur].second;
            cur = pai[cur].first;
        }
        cycles.back().push_back(cur);
        inCycle[cur] = 1;
        tamanhos.push_back(tam);
        return;
    }
    visited[u] = 1;
    for (auto [v, c] : graph[u]) {
        if (v == p) continue;
        pai[v] = {u, c};
        dfs(v, u, c);
    }
}

void dijkstra(int source) {
    memset(visited, 0, sizeof(visited));
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, source);

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = 1;

        for (auto [v, c] : graph[u]) {
            if (dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                pq.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    dfs(1, -1, 0);

    int K; cin >> K;
    while (K--) {
        int X, T; cin >> X >> T;
        dijkstra(X);

        int ans = 0x3f3f3f3f;
        for (int i = 0; i < cycles.size(); i++) {
            if (tamanhos[i] < T) continue;
            for (auto x : cycles[i]) {
                ans = min(ans, 2 * dist[x] + tamanhos[i]);
            }
        }

        cout << ((ans == 0x3f3f3f3f) ? -1 : ans) << "\n";
    }
}