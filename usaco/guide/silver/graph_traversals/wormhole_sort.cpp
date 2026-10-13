#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

#define MAXN 100001

int n, m, pos[MAXN], cow[MAXN];
bool visited[MAXN];
vector<pi> graph[MAXN];
set<int> comp;

void dfs(int u, int mn) {
    if (visited[u]) return;
    visited[u] = true;
    comp.insert(u);
    for (auto [v, c] : graph[u]) {
        if (c < mn) continue;
        dfs(v, mn);
    }
}

bool check(int x) {
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        dfs(i, x);
        for (auto p : comp) {
            if (comp.find(cow[p]) == comp.end()) return false;
        }
        comp.clear();
    }
    return true;
}

int bsearch() {
    int ini = 0, fim = (int) 1e9 + 10;
    while (fim - ini > 1) {
        int meio = (ini + fim) >> 1;
        if (check(meio)) ini = meio;
        else fim = meio;
    }
    return ini;
}

int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    bool aight = true;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
        cow[pos[i]] = i;
        if (i != pos[i]) aight = false;
    }

    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }

    if (aight) {
        cout << "-1\n";
        return 0;
    }

    cout << bsearch() << "\n";
}