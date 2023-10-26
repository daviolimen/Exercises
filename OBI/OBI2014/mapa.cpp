#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 100000

int many;
vector<int> graph[MAXN];
bool visited[MAXN];

void dfs(int u) {
    many++;
    visited[u] = true;

    for (auto v : graph[u]) {
        if (visited[v]) continue;
        dfs(v);
    }
}

int main() {
    int n; cin >> n;

    for (int i = 0; i < (n - 1); i++) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        if (c == 0) {
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }

    for (int i = 0; i < n; i++) visited[i] = false;

    ll result = n * (n - 1) / 2;

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        many = 0;
        dfs(i);
        result -= (ll) many * (many - 1) / 2;
    }

    cout << result << "\n";
}