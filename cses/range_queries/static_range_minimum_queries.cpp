#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001
#define MAXLOG 19

int n, q, arr[MAXN], st[MAXLOG][MAXN];

int roundLog2(int x) {
    return x ? (__builtin_clzll(1) - __builtin_clzll(x)) : -1;
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    copy_n(arr + 1, n, st[0] + 1);

    for (int i = 1; i < MAXLOG; i++) {
        for (int j = 1; j <= n; j++) {
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }

    int a, b;
    while (q--) {
        cin >> a >> b;
        int lg = roundLog2(b - a + 1);
        cout << min(st[lg][a], st[lg][b - (1 << lg) + 1]) << "\n";
    }
}