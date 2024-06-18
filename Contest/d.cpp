#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;

long long n, c, votes[MAXN], prefix[MAXN], sparse[20][MAXN];

long long log2massa(long long x) {
    return(x ? (63 - __builtin_clzll(x)) : -1);
}

long long query(int a, int b) {
    if ((b - a + 1) <= 0) return -1;
    int lg = log2massa(b - a + 1);
    return max(sparse[lg][a], sparse[lg][b - (1 << lg) + 1]);
}

int main() {
    
    int t; cin >> t;
    while (t--) {
        cin >> n >> c;
        for (int i = 1; i <= n; i++) {
            cin >> votes[i];
            prefix[i] = prefix[i - 1] + votes[i];
            sparse[0][i] = votes[i];
        }

        for (int i = 1; i < 20; i++) {
            for (int j = 1; j <= n; j++) {
                sparse[i][j] = max(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (i > 1) cout << " ";
            int mxl = query(1, i - 1), mxr = query(i + 1, n), mx = max(mxl, mxr);
            if (i == 1) {
                if (votes[i] + c >= mx) {
                    cout << 0;
                } else {
                    cout << 1;
                }
            } else {
                if ((votes[i] > mxl) && (votes[i] >= mxr) && (votes[i] > votes[1] + c)) {
                    cout << 0;
                } else {
                    if (prefix[i] + c >= mxr) cout << (i - 1);
                    else cout << i;
                }
            }
        }
        cout << "\n";
    }
}