#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        set<int> prev, curr;
        prev.insert(arr[0]);
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (prev.empty()) {
                ans++;
                prev = curr;
                curr.clear();
                
            }
            if (prev.count(arr[i])) prev.erase(arr[i]);
            curr.insert(arr[i]);
        }

        if (prev.empty()) ans++;

        cout << ans << "\n";
    }
}