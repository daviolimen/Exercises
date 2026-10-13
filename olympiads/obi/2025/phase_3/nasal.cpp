#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100
#define int long long

int n, k;
pair<int, int> arr[MAXN];

int32_t main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i].first;
    for (int i = 0; i < n; i++) cin >> arr[i].second;

    int total = 0;
    vector<int> after;
    for (int i = 0; i < n; i++) {
        if (arr[i].first - arr[i].second >= 0) {
            total += arr[i].first - arr[i].second;
            after.push_back(arr[i].second);
        } else {
            after.push_back(arr[i].first);            
        }
    }

    sort(after.rbegin(), after.rend());

    for (int i = 0; i < min(k + 1, (int) after.size()); i++) {
        total += after[i];
    }

    cout << total << "\n";
}