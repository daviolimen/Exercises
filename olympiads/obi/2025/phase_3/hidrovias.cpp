#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100

int n, m, k, pai[MAXN], peso[MAXN];
array<int, 3> edges[MAXN];

int find(int x) {
    if (x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;
    if (peso[y] < peso[x]) pai[y] = x;
    else if (peso[x] < peso[y]) pai[x] = y;
    else {
        pai[y] = x;
        peso[x]++;
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) pai[i] = i;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
    }

    sort(edges, edges + m);

    int num = 0;
    bool ans = true;
    for (int i = 0; i < m; i++) {
        auto [t, a, b] = edges[i];
        if (find(a) == find(b)) {
            num++;
            if (t == 1) ans = false;
            continue;
        }
        join(a, b);
    }

    if (num > k) ans = false;
    cout << ((ans) ? "S\n" : "N\n");
}