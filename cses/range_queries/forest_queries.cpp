#include <bits/stdc++.h>
using namespace std;

#define MAXN 1002

int n, q, prefix[MAXN][MAXN];

int main() {
    cin >> n >> q;
    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            if (c == '*') prefix[i][j]++;
        }
    }

    int y1, x1, y2, x2;
    while (q--) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << (prefix[y2][x2] - prefix[y2][x1 - 1] - prefix[y1 - 1][x2] + prefix[y1 - 1][x1 - 1]) << "\n";
    }
}