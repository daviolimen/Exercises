#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int n, pai[MAXN];
vector<int> pops, graph[MAXN];
bool mark[MAXN];

void dfs(int x, int p) {
    for (auto v : graph[x]) {
        if (v == p) continue;
        dfs(v, x);
    }

    pops.push_back(x);
    pai[x] = p;
}

int solve() {
    int res = 0;

    for (auto v : pops) {
        if (!mark[v] && !mark[pai[v]]) {
            mark[v] = mark[pai[v]] = 1;
            res++;
        } 
    }
    return res;
}

int main() {
    cin >> n;
    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    mark[0] = 1;

    dfs(1, 0);
    cout << solve() << "\n";
}