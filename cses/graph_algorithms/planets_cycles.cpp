#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;

int steps, prox[MAXN], pathLength[MAXN];
bool visited[MAXN];
queue<int> path;

void dfs(int u) {
    path.push(u);
    if (visited[u]) {
        steps += pathLength[u];
        return;
    }
    visited[u] = 1;
    steps++;
    dfs(prox[u]);
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> prox[i];

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        steps = 0;
        dfs(i);
        int dec = 1;
        while (!path.empty()) {
            if (path.front() == path.back()) {
                dec = 0;
            }
            pathLength[path.front()] = steps;
            steps -= dec;
            path.pop();
        }
    }

    for (int i = 1; i <= n; i++) cout << pathLength[i] << "\n";
}