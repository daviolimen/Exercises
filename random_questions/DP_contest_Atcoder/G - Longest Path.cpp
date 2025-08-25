#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, m;
vector<int> topoSort, graph[MAXN];
bool visited[MAXN];

void dfs(int u) {
    for (auto v : graph[u]) {
        dfs(v);
    }
    if (!visited[u]) {
        topoSort.push_back(u);
        visited[u] = true;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }

    reverse(topoSort.begin(), topoSort.end());

    for (auto x : topoSort) {
        cout << x << " ";
    }
}