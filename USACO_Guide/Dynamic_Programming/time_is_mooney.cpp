#include <bits/stdc++.h>
using namespace std;

#define MAXN 1001

int n, m, c, cost[MAXN];
vector<int> graph[MAXN];

int main() {
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) cin >> cost[i];
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    
}