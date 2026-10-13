#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100100;

int n, k, pai[MAXN];
bool visited[MAXN];
vector<int> graph[MAXN];

void dfs(int u, int p) {
    pai[u] = p;
    for (auto v : graph[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0, -1);
    cin >> k;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        int cnt = 0;
        while (pai[x] != -1) {
            if (visited[x]) break;
            visited[x] = 1;
            cnt++;
            x = pai[x];
        }
        ans += cnt;
    }
    cout << ans * 2 << "\n";
}