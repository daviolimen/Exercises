#include <bits/stdc++.h>
using namespace std;

#define MAXN 1001

int n, q, prefix[MAXN][MAXN];

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char a; cin >> a;
            int add = (a == '.') ? 0 : 1;
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + add;
        }
    }

    while (q--) {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        cout << (prefix[y2][x2] - prefix[y2][x1 - 1] - prefix[y1 - 1][x2] + prefix[y1 - 1][x1 - 1]) << "\n";
    }
}