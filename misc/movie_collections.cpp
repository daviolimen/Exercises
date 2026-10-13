#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int m, r, bit[MAXN];

void update(int k, int p) {
    for (; k <= m; k += (k & -k)) {
        bit[k] += p;
    }
}

int soma(int k) {
    int res = 0;
    for (; k > 0; k -= (k & -k)) {
        res += bit[k];
    }
    return res;
}

int main() {
    int tt; cin >> tt;
    while (tt--) {
        cin >> m >> r;
        for (int i = 1; i <= m; i++) {
            update(i, 1);
        }
        for (int i = 1; i <= m; i++) {
            cout << bit[i] << "\n";
        }
    }
}