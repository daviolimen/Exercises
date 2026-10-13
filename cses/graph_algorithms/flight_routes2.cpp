#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ull, int> pli;
 
#define MAXN 100001
 
int n, m, k;
vector<ull> dist[MAXN];
vector<pi> graph[MAXN];
 
void dijkstra(int start, int end) {
    priority_queue<pli, vector<pli>, greater<pli>> heap;
    heap.emplace(0, start);
 
    while (!heap.empty()) {
        auto [cost, u] = heap.top(); heap.pop();
 
        if (dist[u].size() >= k) continue;
 
        dist[u].push_back(cost);
 
        for (auto [v, c] : graph[u]) {
            if (dist[v].size() >= k) continue;
            heap.emplace(cost + (ull) c, v);
        }
    }
    for (auto d : dist[end]) {
        cout << d << " ";
    }
    cout << "\n";
}
 
int main() {
    cin >> n >> m >> k;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }
    dijkstra(1, n);
}