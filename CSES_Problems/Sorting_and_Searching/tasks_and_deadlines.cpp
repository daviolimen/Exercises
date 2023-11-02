#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int n;
pair<int, int> arr[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

    sort(arr, arr + n);

    long long time = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        time += arr[i].first;
        ans += (long long) arr[i].second - time;
    }

    cout << ans << "\n";
}