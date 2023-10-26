#include <bits/stdc++.h>
using namespace std;

const int INF = (int) 1e9;

int Do(int a, int b, int op) {
    if (op == 0) {
        return a + b;
    } else if (op == 1) {
        return a - b;
    } else if (op == 2) {
        return a * b;
    } else if (op == 3) {
        if (b && (a % b == 0)) return a / b;
    }
    return -INF;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        vector<int> seq(4);
        for (int i = 0; i < 4; i++) cin >> seq[i];

        sort(seq.begin(), seq.end());

        int mx = -INF;

        do {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k < 4; k++) {
                        int a = seq[0], b = seq[1], c = seq[2], d = seq[3];

                        int v1 = Do(Do(Do(a, b, i), c, j), d, k);
                        if ((v1 >= 0) && (v1 <= 24)) mx = max(mx, v1);

                        int v2 = Do(Do(a, b, i), Do(c, d, k), j);
                        if ((v2 >= 0) && (v2 <= 24)) mx = max(mx, v2);

                        int v3 = Do(Do(a, Do(b, c, j), i), d, k);
                        if ((v3 >= 0) && (v3 <= 24)) mx = max(mx, v3);

                        int v4 = Do(a, Do(Do(b, c, j), d, k), i);
                        if ((v4 >= 0) && (v4 <= 24)) mx = max(mx, v4);

                        int v5 = Do(a, Do(b, Do(c, d, k), j), i);
                        if ((v5 >= 0) && (v5 <= 24)) mx = max(mx, v5);
                    }
                }
            }
        } while (next_permutation(seq.begin(), seq.end()));
        cout << mx << "\n";
    }
}