#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int n, m;
vector<int> graph[MAXN];
bool visited[MAXN];

void dfs(int u) {
    if (visited[u]) return;
    visited[u] = 1;
    for (auto v : graph[u]) {
        dfs(v);
    }
}

int main() {
    while (true) {
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < MAXN; i++) graph[i].clear();
        cin >> n >> m;
        if (n == 0) break;

        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        dfs(1);

        bool con = 1;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                con = 0;
                break;
            }
        }

        cout << ((con) ? "SIM" : "NAO") << "\n";
    }
}