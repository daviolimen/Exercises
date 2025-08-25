#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    scanf("%d%d", &n, &m);
    unordered_set<int> figs;
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        figs.insert(x);
    }
    int ans = n - figs.size();
    printf("%d\n", ans);
}