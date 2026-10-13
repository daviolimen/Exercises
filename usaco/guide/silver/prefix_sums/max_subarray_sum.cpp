#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int n, arr[MAXN];
long long prefix[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + (long long) arr[i];
    }

    long long ans = (long long) -1e15, mn = 0;

    for (int i = 1; i <= n; i++) {
        ans = max(ans, prefix[i] - mn);
        mn = min(mn, prefix[i]);
    }

    cout << ans << "\n";
}