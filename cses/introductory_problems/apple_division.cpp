#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 20

int n, arr[MAXN];

ll diff(int mask) {
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            sum1 += arr[i];
        } else {
            sum2 += arr[i];
        }
    }
    return abs(sum1 - sum2);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll ans = 1e15;
    for (int i = 0; i < (1 << n); i++) {
        ans = min(ans, diff(i));
    }
    cout << ans << "\n";
}