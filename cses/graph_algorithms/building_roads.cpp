#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 100001
 
int n, m, pai[MAXN], peso[MAXN];
vector<pair<int, int>> edges;
 
int find(int x) {
    if (pai[x] == x) return x;
 
    return pai[x] = find(pai[x]);
}
 
void join(int x, int y) {
    x = find(x);
    y = find(y);
 
 
    if (peso[y] < peso[x]) {
        pai[y] = x;
    } else if (peso[x] < peso[y]) {
        pai[x] = y;
    } else {
        pai[y] = x;
        peso[x]++;
    }
}
 
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) pai[i] = i;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        join(a, b);
    }
 
    vector<pair<int, int>> newEdges;
 
    for (int i = 1; i < n; i++) {
        if (find(i) != find(i + 1)) {
            newEdges.emplace_back(i, i + 1);
            join(i, i + 1);
        }
    }
 
    cout << newEdges.size() << "\n";
    for (auto [x, y] : newEdges) {
        cout << x << " " << y << "\n";
    }
}