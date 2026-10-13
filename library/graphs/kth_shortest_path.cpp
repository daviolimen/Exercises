#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

#define MAXN 100001

int n, m, k;
vector<int> dist[MAXN];
vector<pi> graph[MAXN];

void dijsktra(int start, int end) {
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    heap.emplace(0, start);

    while (!heap.empty()) {
        auto [cost, u] = heap.top(); heap.pop();

        if (dist[u].size() == k) continue;

        if ((dist[u].empty()) || (dist[u].back() != cost)) dist[u].push_back(cost);

        for (auto [v, c] : graph[u]) {
            if (dist[v].size() == k) continue;
            heap.emplace(cost + c, v);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    
}