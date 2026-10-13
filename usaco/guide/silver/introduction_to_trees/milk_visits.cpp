#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int n, m, numOfComps, comp[MAXN];
bool milk[MAXN];
vector<int> graph[MAXN];

void dfs(int u, int p) {
    if (milk[u] == milk[p]) comp[u] = comp[p];
    else comp[u] = ++numOfComps;
    for (auto v : graph[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        milk[i] = (c == 'H') ? 0 : 1;
    }
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    string ans;
    for (int i = 0; i < m; i++) {
        int a, b; char c; cin >> a >> b >> c;
        if (comp[a] != comp[b]) ans.push_back('1');
        else {
            int teste = (c == 'H') ? 0 : 1;
            if (milk[a] == teste) ans.push_back('1');
            else ans.push_back('0');
        }
    }

    cout << ans << "\n";
}