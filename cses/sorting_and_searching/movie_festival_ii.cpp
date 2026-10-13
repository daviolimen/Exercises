#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int n, k;
pair<int, int> arr[MAXN];
multiset<int> ms;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i].second >> arr[i].first;

    sort(arr, arr + n);

    for (int i = 0; i < k; i++) ms.insert(0);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        auto it = ms.upper_bound(arr[i].second);
        if (it == ms.begin()) {
            continue;
        }
        ans++;
        it--;
        ms.erase(it);
        ms.emplace(arr[i].first);
    }

    cout << ans << "\n";
}