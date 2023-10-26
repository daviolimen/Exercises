#include <bits/stdc++.h>
using namespace std;

#define MAXN 50001

int n, m, pai[MAXN], peso[MAXN];

void init() {
    for (int i = 0; i < MAXN; i++) {
        pai[i] = i;
        peso[i] = 0;
    }
}

int find(int x) {
    if (pai[x] == x) return x;

    return pai[x] = find(pai[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (peso[x] < peso[y]) pai[x] = y;
    else if (peso[y] < peso[x]) pai[y] = x;
    else {
        pai[y] = x;
        peso[x]++;
    }
}

int main() {
    int ctr = 1;
    while (true) {
        init();

        cin >> n >> m;
        if ((n == 0) && (m == 0)) break;

        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            join(a, b);
        }

        int ans = 0;
        bool visited[MAXN];
        memset(visited, 0, MAXN);

        for (int i = 1; i <= n; i++) {
            if (visited[find(i)]) continue;
            ans++;
            visited[find(i)] = true;
        }

        cout << "Case " << ctr << ": " << ans << "\n";
        ctr++;
    }
}