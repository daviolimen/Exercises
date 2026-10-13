#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, m, r, milk[MAXN], rent[MAXN];
pair<int, int> stores[MAXN];

bool intCmp(int a, int b) {
    return a > b;
}

bool pairCmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second > b.second;
}

int main() {
    // freopen("rental.in", "r", stdin);
    // freopen("rental.out", "w", stdout);

    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) cin >> milk[i];
    for (int i = 0; i < m; i++) cin >> stores[i].first >> stores[i].second;
    for (int i = 0; i < r; i++) cin >> rent[i];

    sort(milk, milk + n, intCmp);
    sort(stores, stores + m, pairCmp);
    sort(rent, rent + r, intCmp);

    for (int i = 0; i < r; i++) cout << rent[i] << " ";
}