#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> cycle;
vector<bool> onStack, visited;

bool dfs(int u) {
    onStack[u] = visited[u] = 1;
    for (auto v : adj[u]) {
        if (onStack[v]) {
            onStack[v] = onStack[u] = 0;
            cycle.push_back(u);
            return 1;
        } else if (!visited[v]) {
            if (dfs(v)) {
                if (onStack[u]) {
                    onStack[u] = 0;
                    cycle.push_back(u);
                    return 1;
                } else {
                    cycle.push_back(u);
                    return 0;
                }
            }

            if (!cycle.empty()) return 0;
        }
    }

    onStack[u] = 0;
    return 0;
}

int main() {
    int n, m; cin >> n >> m;
    adj = vector<vector<int>>(n);
    visited = vector<bool>(n);
    onStack = vector<bool>(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
    }

    for (int i = 0; cycle.empty() && i < n; i++) dfs(i);

    if (cycle.empty()) cout << "IMPOSSIBLE\n";
    else {
        reverse(cycle.begin(), cycle.end());
        cycle.push_back(cycle[0]);
        cout << cycle.size() << "\n";
        for (auto x : cycle) cout << (x + 1) << " ";
        cout << "\n";
    }
}