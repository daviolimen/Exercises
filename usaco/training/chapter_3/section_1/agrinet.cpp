/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: agrinet
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;

int n, par[MAXN], aux[MAXN];

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (aux[x] == aux[y]) {
        par[y] = x;
        aux[x]++;
    } else if (aux[x] > aux[y]) {
        par[y] = x;
    } else {
        par[x] = y;
    }
}

int main() {
    ifstream cin ("agrinet.in");
    ofstream cout ("agrinet.out");
    for (int i = 1; i <= 100; i++) {
        par[i] = i;
        aux[i] = 1;
    }
    cin >> n;
    vector<tuple<int, int, int>> edgeList;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            edgeList.emplace_back(x, i, j);
            edgeList.emplace_back(x, j, i);
        }
    }

    sort(edgeList.begin(), edgeList.end());
    int ans = 0;

    for (int i = 0; i < (int) edgeList.size(); i++) {
        auto [cost, x, y] = edgeList[i];
        if (find(x) == find(y)) continue;
        join(x, y);
        ans += cost;
    }

    cout << ans << "\n";
    return 0;
}