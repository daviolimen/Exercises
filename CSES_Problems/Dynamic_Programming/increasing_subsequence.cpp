#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int n, arr[MAXN];

int LIS() {
    vector<int> ans;
    ans.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i] > ans.back()) {
            ans.push_back(arr[i]);
        } else {
            int idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[idx] = arr[i];
        }
    }
    return ans.size();
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << LIS() << "\n";
}