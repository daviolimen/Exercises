#include <bits/stdc++.h>
using namespace std;

int n, arr[100001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ans = 0;
    accumulate(arr, arr + n, ans);
    cout << ans << "\n";
}