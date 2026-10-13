#include <bits/stdc++.h>
using namespace std;

#define MAXN 10001

int N, M, L, T, counter;
vector<int> graph[MAXN];
bool visited[MAXN];

void dfs(int start) {
    if (visited[start]) return;
    counter++;
    visited[start] = true;
    for (auto x : graph[start]) dfs(x);
}

int main() {
    int x, y, z;
    cin >> T;
    for (int I = 0; I < T; I++) {
        cin >> N >> M >> L;
        counter = 0;
        for (auto &x : graph) {
            x.clear();
        }
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < M; i++) {
            cin >> x >> y;
            graph[x].push_back(y);
        }
        for (int i = 0; i < L; i++) {
            cin >> z;
            dfs(z);
        }
        cout << counter << "\n";
    }
}