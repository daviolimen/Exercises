#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int x, n, arr[MAXN];

int main() {
    cin >> x >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    long long ans = 0, curr = (long long) arr[0];

    

    cout << ans << "\n";
}