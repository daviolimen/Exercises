#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, tam[MAXN];
vector<int> graph[MAXN];

void dfs(int u, int p) {
    for (auto v : graph[u]) {
        if (v == p) continue;
        dfs(v, u);
        tam[u] += tam[v];
    }
    tam[u]++;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, -1);

    int ans = INT_MAX;

    for (int i = 1; i <= n; i++) {
        if (abs(n - 2 * tam[i]) < ans) {
            ans = abs(n - 2 * tam[i]);
        }
    }

    cout << ans << "\n";
}