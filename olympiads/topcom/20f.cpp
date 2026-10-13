#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

int n, m, arr[MAXN];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int l = 0, r = 0, res = m + 1;

    while (r < (n - 2)) {
        if ((arr[r + 1] - arr[r] - 1) > m) {
            m += arr[l + 1] - arr[l] - 1;
            l++;
            continue;
        }
        r++;
        if ((arr[r] - arr[r - 1] - 1) <= m) {
            m -= arr[r] - arr[r - 1] - 1;
            res = max(res, arr[r] - arr[l] + 1 + m);
            continue;
        }
    }

    cout << res << "\n";
}