#include <bits/stdc++.h>
using namespace std;

#define MAXN 20000

int n, pai[MAXN], peso[MAXN];

int find(int x) {
    if (pai[x] == x) return x;

    return pai[x] = find(pai[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if (peso[x] < peso[y]) pai[x] = y;
    else if (peso[y] < peso[x]) pai[y] = x;
    else {
        pai[y] = x;
        peso[x]++;
    }
}

int en(int x) {
    return x + n;
}

int main() {
    for (int i = 0; i < MAXN; i++) pai[i] = i;
    cin >> n;

    int c, x, y;
    while (true) {
        cin >> c >> x >> y;
        if ((c == 0) && (x == 0) && (y == 0)) break;
        if (c == 1) {
            if ((find(x) == find(en(y))) || (find(en(x)) == find(y))) cout << "-1\n";
            else {
                join(x, y);
                join(en(x), en(y));
            }
        } else if (c == 2) {
            if ((find(x) == find(y)) || (find(en(x)) == find(en(y)))) cout << "-1\n";
            else {
                join(en(x), y);
                join(x, en(y));
            }
        } else if (c == 3) {
            if ((find(x) == find(y)) || (find(en(x)) == find(en(y)))) cout << "1\n";
            else cout << "0\n";
        } else if (c == 4) {
            if ((find(x) == find(en(y))) || (find(en(x)) == find(y))) cout << "1\n";
            else cout << "0\n";
        }
    }
}