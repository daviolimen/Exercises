#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int n, m, compSize[MAXN];
unordered_set<int> comp[MAXN], graph[MAXN];
bool visited[MAXN];

void dfs(int u, int c) {
    compSize[c]++;
    comp[c].insert(u);
    visited[u] = true;
    for (auto v : graph[u]) {
        if (visited[v]) continue;
        dfs(v, c);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }   

    int currC = 0;

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        dfs(i, ++currC);
    }

    for (int i = 1; i <= currC; i++) {
        for (auto u : comp[i]) {
            if (graph[u].size() >= (compSize[i] - 1)) continue;

            for (auto v : comp[i]) {
                if ((v == u) || (graph[u].find(v) != graph[u].end())) continue;

                cout << u << " " << v << "\n";
                return 0;
            }
        }
    }

    cout << "-1\n";
    return 0;
}