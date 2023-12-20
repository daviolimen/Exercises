#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int n, arr[MAXN], sorted[MAXN];

int main() {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    copy(arr, arr + n, sorted);
    sort(sorted, sorted + n);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != sorted[i]) ans++;
    }

    cout << ans - 1 << "\n";
}