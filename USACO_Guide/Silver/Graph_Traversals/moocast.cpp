#include <bits/stdc++.h>
using namespace std;

#define MAXN 200

int n, ctr;
bool visited[MAXN];
vector<int> graph[MAXN];

bool dist(int x1, int y1, int x2, int y2, int p) {
    if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= (p * p)) return true;
    return false;
}

void dfs(int u) {
    if (visited[u]) return;
    ctr++;
    visited[u] = true;
    for (auto v : graph[u]) {
        dfs(v);
    }
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    cin >> n;

    int cow[MAXN][3];
    for (int i = 0; i < n; i++) {
        cin >> cow[i][0] >> cow[i][1] >> cow[i][2];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (dist(cow[i][0], cow[i][1], cow[j][0], cow[j][1], cow[i][2])) graph[i].push_back(j);
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ctr = 0;
        memset(visited, 0, sizeof(visited));
        dfs(i);
        ans = max(ans, ctr);
    }

    cout << ans << "\n";
}