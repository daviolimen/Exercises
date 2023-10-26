#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

#define MAXN 200001

int n;
vector<int> graph[MAXN];

pi dfs(int x, int p) {
    pi res = {0, x};
    for (auto v : graph[x]) {
        if (v == p) continue;
        pi d = dfs(v, x);
        res = max(res,{d.first + 1, d.second});
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

    pi par1 = dfs(1, 0);
    cout << dfs(par1.second, 0).first << "\n";
}