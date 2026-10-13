#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int n, x, arr[MAXN];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);

    int i = 0, j = n - 1, ans = 0;
    while (i <= j) {
        if (i == j) {
            ans++;
            break;
        }
        if (arr[i] + arr[j] <= x) {
            ans++;
            i++;
            j--;
        } else {
            ans++;
            j--;
        }
    }
    cout << ans << "\n";
}