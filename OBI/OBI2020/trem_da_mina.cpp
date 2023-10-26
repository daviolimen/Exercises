#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10001, INF = (int) 1e9 + 10;

int e, r, mark[MAXN], esta[MAXN], ate[MAXN], Tciclo[MAXN], dist[MAXN], Tcaminho;
vector<int> caminho;
vector<pair<int, int>> graph[MAXN];

void dfs(int u, int anterior) {
    mark[u] = 1;
    esta[u] = 1;
    ate[u] = Tcaminho;
    caminho.push_back(u);

    for (auto [v, w] : graph[u]) {
        if ((esta[v]) && (v != anterior)) {
            while (true) {
                Tciclo[caminho.back()] = ate[u] - ate[v] + w;
                esta[caminho.back()] = 0;
                if (caminho.back() == v) {
                    caminho.pop_back();
                    break;
                }
                caminho.pop_back();
            }
        } else if (mark[v] == 0) {
            Tcaminho += w;
            dfs(v, u);
            Tcaminho -= w;
        }
    }

    if (esta[u]) {
        esta[u] = 0;
        caminho.pop_back();
    }
}

void dijkstra(int start) {
    for (int i = 1; i <= e; i++) dist[i] = INF;
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.emplace(0, start);

    while (!heap.empty()) {
        auto [cost, u] = heap.top();
        heap.pop();

        if (dist[u] < cost) continue;

        for (auto [v, c] : graph[u]) {
            if (dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                heap.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> e >> r;
    for (int i = 0; i < r; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    for (int i = 1; i <= e; i++) {
        if (mark[i]) continue;
        dfs(i, 0);
    }

    int k; cin >> k;

    while (k--) {
        int x, t; cin >> x >> t;
        dijkstra(x);
        int ans = INT_MAX;
        for (int i = 1; i <= e; i++) {
            if (Tciclo[i] >= t) {
                ans = min(ans, 2 * dist[i] + Tciclo[i]);
            }
        }

        cout << ((ans == INT_MAX) ? -1 : ans);
        cout << "\n";
    }
}