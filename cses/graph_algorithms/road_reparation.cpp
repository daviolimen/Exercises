#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001, MAXM = 200001;

#define int long long

struct edge {
    int a, b, c;
};

bool cmp(const edge &a, const edge &b) {
    return a.c < b.c;
}

int n, m, pai[MAXN], peso[MAXN];
edge edgeList[MAXM];

int find(int x) {
    if (pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (peso[x] > peso[y]) pai[y] = x;
    if (peso[y] > peso[x]) pai[x] = y;
    if (peso[x] == peso[y]) {
        pai[y] = x;
        peso[x]++;
    }
}

int32_t main() {
    for (int i = 0; i < MAXN; i++) pai[i] = i;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> edgeList[i].a >> edgeList[i].b >> edgeList[i].c;
    }
    sort(edgeList, edgeList + m, cmp);

    int cost = 0;

    for (int i = 0; i < m; i++) {
        if (find(edgeList[i].a) != find(edgeList[i].b)) {
            cost += edgeList[i].c;
            join(edgeList[i].a, edgeList[i].b);
        }
    }

    for (int i = 1; i < n; i++) {
        if (find(i) != find(i + 1)) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    cout << cost << "\n";
}