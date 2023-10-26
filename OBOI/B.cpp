#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, arr[MAXN];

int main() {
    cin >> n;
    long long ans = 0, curr = n;
    for (int i = 1; i <= n; i++) {
        ans += (long long) abs(curr - i);
        curr--;
    }

    cout << ans << "\n";
}