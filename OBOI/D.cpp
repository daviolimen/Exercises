#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int, int, int, int, int> ti;

const int MAXN = 100001, MAXK = 10001, INF = (int) 1e9 + 10;

int N, M, K, atr[MAXK], visited[MAXN];
vector<pi> graph[MAXN];

int dijkstra() {
    priority_queue<ti, vector<ti>, greater<ti>> heap;
    heap.emplace(0, 0, 0, 0, 0);

    while (!heap.empty()) {
        auto [cost, u, p, l, first] = heap.top(); heap.pop();

        if ((u == 0) && (first != p)) return cost;

        for (auto [v, c] : graph[u]) {
            if (u == 0) heap.emplace(cost + c, v, u, l + 1, v);
            else heap.emplace(cost + c, v, u, l + 1, first);
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

    for (int i = 0; i < K; i++) {
        graph[atr[i]].emplace_back(0, 0);
        graph[0].emplace_back(atr[i], 0);
    }

    cout << dijkstra() << "\n";
}