#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int n, arr[MAXN];
long long prefix[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + n + 1);

    for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + (long long) arr[i];

    int pos = upper_bound(prefix + 1, prefix + n + 1, (prefix[n] / 2)) - 1 - prefix;

    long long ans = prefix[n] + abs(prefix[pos] - (prefix[n] - prefix[pos]));
    cout << ans << "\n";
}