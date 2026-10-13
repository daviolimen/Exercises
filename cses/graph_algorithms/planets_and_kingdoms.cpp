#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int n, m;
vector<int> graph[2][MAXN];
bool visited[2][MAXN];

void dfs(int u, int q) {
    if (visited[q][u]) return;
    visited[q][u] = true;
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

    int curr = 1, ans[MAXN];
    memset(ans, 0, sizeof(ans));

    for (int i = 1; i <= n; i++) {
        if (ans[i]) continue;
        dfs(i, 0);
        dfs(i, 1);
        for (int j = 1; j <= n; j++) {
            if (visited[0][j] && visited[1][j]) ans[j] = curr;
        }
        memset(visited, 0, sizeof(visited));
        curr++;
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}