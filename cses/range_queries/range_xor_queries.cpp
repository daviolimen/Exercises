#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;

int n, q, arr[MAXN][31];

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        for (int j = 0; j < 31; j++) {
            arr[i][j] = arr[i - 1][j];
            if (x & (1 << j)) arr[i][j]++;
        }
    }

    while (q--) {
        int a, b; cin >> a >> b;
        int res = 0;
        for (int i = 0; i < 31; i++) {
            if ((arr[b][i] - arr[a - 1][i]) % 2 == 1) res |= (1 << i);
        }
        cout << res << "\n";
    }
}