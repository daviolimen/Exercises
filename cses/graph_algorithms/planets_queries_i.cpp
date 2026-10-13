#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001
#define MAXLOG 31

int n, q, prox[MAXLOG][MAXN];

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> prox[0][i];

    for (int i = 0; i < (MAXLOG - 1); i++) {
        for (int j = 1; j <= n; j++) {
            prox[i + 1][j] = prox[i][prox[i][j]];
        }
    }

    int x, k;
    while (q--) {
        cin >> x >> k;
        for (int i = 0; i < MAXLOG; i++) {
            if (k & (1 << i)) x = prox[i][x];
        }
        cout << x << "\n";
    }
}