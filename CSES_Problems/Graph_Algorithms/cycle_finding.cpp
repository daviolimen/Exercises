#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

const int MAXN = 2501;

int n, m, value;
vector<int> cycle;
vector<pi> graph[MAXN];
bool visited[MAXN];

bool negCycle(int u) {
    visited[u] = 1;
    for (auto [v, c] : graph[u]) {
        cycle.push_back(u);
        if (!visited[v]) {
            if (negCycle(v)) return 1;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }

    for (int i = 1; i <= n; i++) {
        
    }
}