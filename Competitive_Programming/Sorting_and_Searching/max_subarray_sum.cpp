#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 200001

int n, arr[MAXN];
ll prefix[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + (ll) arr[i];
    }

    int menor = 0;
    ll ans = INT_MIN;

    for (int i = 1; i <= n; i++) {
        if (prefix[i - 1] < prefix[menor]) {
            menor = i - 1;
        }
        ans = max(ans, prefix[i] - prefix[menor]);
    }

    cout << ans << "\n";
}