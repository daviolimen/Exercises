#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

int n, m, pai[MAXN];
bool groups[MAXN];

int find(int x) {
    if (pai[x] == x) return x;

    return pai[x] = find(pai[x]);
}

void join(int x, int y) {
    pai[find(x)] = find(y);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) pai[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        join(a, b);
    }

    int counter = 0;
    for (int i = 1; i <= n; i++) {
        if (groups[find(i)]) continue;
        groups[find(i)] = true;
        counter++;
    }
    cout << counter << "\n";
}