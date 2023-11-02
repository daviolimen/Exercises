#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int n, arr[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    long long ans = 1LL * arr[n - 1] * arr[n - 2] * arr[n - 3];
    cout << ans << "\n";
}