#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;

int n, m, d, des[MAXN], val[MAXN];

int main() {
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) cin >> des[i];
    for (int i = 0; i < m; i++) cin >> val[i];
    sort(des, des + n);
    sort(val, val + m);

    int a = 0, b = 0, res = 0;

    while ((a < n) && (b < m)) {
        if (abs(des[a] - val[b]) <= d) {
            res++;
            a++;
            b++;
            continue;
        }
        if (des[a] > val[b]) {
            b++;
            continue;
        }
        if (val[b] > des[a]) {
            a++;
            continue;
        }
    }

    cout << res << "\n";
}