#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, m;
vector<int> graph[2][MAXN];
bool visited[MAXN];

void dfs(int u, int q) {
    if (visited[u]) return;
    visited[u] = true;
    for (auto v : graph[q][u]) {
        dfs(v, q);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[0][a].push_back(b);
        graph[1][b].push_back(a);
    }

    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << "1 " << i << "\n";
            return 0;
        }
    }

    memset(visited, 0, sizeof(visited));

    dfs(1, 1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << i << " 1\n";
            return 0;
        }
    }

    cout << "YES\n";
}