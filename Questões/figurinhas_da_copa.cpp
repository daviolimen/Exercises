#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c, m, f;
    scanf("%d%d%d", &n, &c, &m);
    set<int> carimbadas, compradas, result;
    for (int i = 0; i < c; i++) {
        scanf("%d", &f);
        carimbadas.insert(f);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &f);
        compradas.insert(f);
    }
    set_difference(carimbadas.begin(), carimbadas.end(), compradas.begin(), compradas.end(), inserter(result, result.end()));
    int ans = result.size();
    printf("%d\n", ans);
}