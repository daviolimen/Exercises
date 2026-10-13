#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

#define MAXN 5001

int n, q;
vector<pi> graph[MAXN];

int dfs(int u, int p, int k) {
    int res = 1;
    for (auto [v, c] : graph[u]) {
        if ((v == p) || (c < k)) continue;
        res += dfs(v, u, k);
    }
    return res;
}

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    while (q--) {
        int k, v; cin >> k >> v;
        cout << (dfs(v, -1, k) - 1) << "\n";
    }
}