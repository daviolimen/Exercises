#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, k, bel[MAXN];
long long sub[MAXN];
vector<int> graph[MAXN];

void dfs(int u, int p) {
    for (auto v : graph[u]) {
        if (v == p) continue;
        dfs(v, u);
        sub[u] += sub[v];
    }
    sub[u] += (long long) bel[u];
}

int main() {
    cin >> n >> k;
    long long somaTotal = 0;
    for (int i = 1; i <= n; i++) {
        cin >> bel[i];
        somaTotal += bel[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, -1);

    long long menorSub = 0;

    for (int i = 1; i <= n; i++) {
        menorSub = min(menorSub, sub[i]);
    }

    cout << (somaTotal - menorSub) << "\n";
}