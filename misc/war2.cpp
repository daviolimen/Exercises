#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000

int n, peso[MAXN];
pair<int, int> pai[MAXN];

void init() {
    for (int i = 0; i < MAXN; i++) pai[i] = {i, 0};
}

pair<int, int> find(int x) {
    if (x != pai[x].first) {
        int len = pai[x].second;
        pai[x] = find(pai[x].first);
        pai[x].second += len;
    }
    return pai[x];
}

void join(int x, int y, int flag) {
    x = find(x).first;
    y = find(y).first;

    if (x == y) return;

    if (peso[x] < peso[y]) pai[x] = {y, flag};
    else if (peso[y] < peso[x]) pai[y] = {x, flag};
    else {
        pai[y] = {x, flag};
        peso[x]++;
    }
}

int main() {
    init();
    cin >> n;
    int c = 1, x = 1, y = 1;
    while (true) {
        cin >> c >> x >> y;
        if ((c == 0) && (x == 0) && (y == 0)) break;

        if (c == 1) {
            if ((find(x).first == find(y).first) && (find(x).second + find(y).second) % 2 == 1) cout << "-1\n";
            else join(x, y, 0);
        } else if (c == 2) {
            if ((find(x).first == find(y).first) && (find(x).second + find(y).second) % 2 == 0) cout << "-1\n";
            else join(x, y, 1);
        } else if (c == 3) {
            if ((find(x).first == find(y).first) && (find(x).second + find(y).second) % 2 == 0) cout << "1\n";
            else cout << "0\n";
        } else if (c == 4) {
            if ((find(x).first == find(y).first) && (find(x).second + find(y).second) % 2 == 1) cout << "1\n";
            else cout << "0\n";
        }
    }
}