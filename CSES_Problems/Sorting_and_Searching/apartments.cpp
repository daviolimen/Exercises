#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int n, m, k, desires[MAXN], sizes[MAXN];

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> desires[i];
    for (int i = 0; i < m; i++) cin >> sizes[i];

    sort(desires, desires+n);
    sort(sizes, sizes+m);

    int i = 0, j = 0, ans = 0;
    while ((i < n) && (j < m)) {
        if (abs(desires[i] - sizes[j]) <= k) {
            ans++;
            i++;
            j++;
        } else if (desires[i] > sizes[j]) {
            j++;
        } else {
            i++;
        }
    }
    cout << ans << "\n";
}