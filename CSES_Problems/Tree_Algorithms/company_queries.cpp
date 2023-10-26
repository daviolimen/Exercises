#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001
#define MAXLOG 19

int n, q, pai[MAXLOG][MAXN];

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> q;
    pai[0][1] = 0;
    for (int i = 2; i <= n; i++) cin >> pai[0][i];

    for (int i = 0; i < (MAXLOG - 1); i++) {
        for (int j = 1; j <= n; j++) {
            pai[i + 1][j] = pai[i][pai[i][j]];
        }
    }

    int x, k;
    while (q--) {
        cin >> x >> k;
        for (int i = 0; i < MAXLOG; i++) {
            if (k & (1 << i)) x = pai[i][x];
        }
        if (x) cout << x << "\n";
        else cout << "-1\n";
    }
}