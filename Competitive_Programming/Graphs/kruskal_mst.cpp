#include <bits/stdc++.h>
using namespace std;

#define MAXN 50001
#define MAXM 100001

struct edge {
    int x, y, dis;
};

bool cmp(edge &a, edge &b) {
    return a.dis < b.dis;
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

    if (peso[x] > peso[y]) {
        pai[y] = x;
    } else if (peso[y] > peso[x]) {
        pai[x] = y;
    } else {
        pai[y] = x;
        peso[x]++;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> edgeList[i].x >> edgeList[i].y >> edgeList[i].dis;
    }
    for (int i = 1; i <= n; i++) pai[i] = i;

    sort(edgeList + 1, edgeList + m + 1, cmp);

    int size = 0;
    edge mst[MAXM];

    for (int i = 1; i <= m; i++) {
        if (find(edgeList[i].x) != find(edgeList[i].y)) {
            join(edgeList[i].x, edgeList[i].y);

            mst[++size] = edgeList[i];
        }
    }

    for (int i = 1; i < n; i++) {
        cout << mst[i].x << " " << mst[i].y << " " << mst[i].dis << "\n";
    }
}