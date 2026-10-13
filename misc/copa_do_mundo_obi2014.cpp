#include <bits/stdc++.h>
using namespace std;

#define MAXN 101
#define MAXM 20001

struct edge {
    int a, b, c, t;
};

bool cmp(edge &a, edge &b) {
    if (a.t == b.t) {
        return a.c < b.c;
    }
    return a.t < b.t;
}

int N, F, R, pai[MAXN], peso[MAXN];
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
    cin >> N >> F >> R;

    for (int i = 1; i <= N; i++) pai[i] = i;

    for (int i = 1; i <= F; i++) {
        cin >> edgeList[i].a >> edgeList[i].b >> edgeList[i].c;
        edgeList[i].t = 0;
    }

    for (int i = F + 1; i <= (F + R); i++) {
        cin >> edgeList[i].a >> edgeList[i].b >> edgeList[i].c;
        edgeList[i].t = 1;
    }

    sort(edgeList + 1, edgeList + 1 + F + R, cmp);

    int ans = 0;

    for (int i = 1; i <= (F + R); i++) {
        if (find(edgeList[i].a) != find(edgeList[i].b)) {
            ans += edgeList[i].c;
            join(edgeList[i].a, edgeList[i].b);
        }
    }

    cout << ans << "\n";
}