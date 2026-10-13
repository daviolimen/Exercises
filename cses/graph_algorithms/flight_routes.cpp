#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ull, int> pli;

#define MAXN 100001

int n, m, k, ctr[MAXN];
vector<ull> routes[MAXN];
vector<pi> graph[MAXN];

void dijkstra(int start, int end) {
    priority_queue<pli, vector<pli>, greater<pli>> heap;
    heap.emplace(0, start);

    while (ctr[end] < k) {
        auto [cost, u] = heap.top(); heap.pop();

        if (ctr[u] >= k) continue;

        ctr[u]++;
        routes[u].push_back(cost);

        for (auto [v, c] : graph[u]) {
            heap.emplace(cost + (ull) c, v);
        }
    }
    
    for (auto c : routes[end]) {
        cout << c << " ";
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