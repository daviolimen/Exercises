#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, pai[MAXN], peso[MAXN];

int find(int x) {
    if (pai[x] == x) return x;

    return pai[x] = find(pai[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if (peso[y] < peso[x]) pai[y] = x;
    else if (peso[x] < peso[y]) pai[x] = y;
    else {
        pai[y] = x;
        peso[x]++;
    }
}

int main() {
    int k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) pai[i] = i;
    while (k--) {
        char op; cin >> op;
        if (op == 'F') {
            int x, y; cin >> x >> y;
            join(x, y);
        } else if (op == 'C') {
            int x, y; cin >> x >> y;
            if (find(x) == find(y)) cout << "S\n";
            else cout << "N\n";
        }
    }
}