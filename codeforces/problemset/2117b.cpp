#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> ans(n);
        ans[0] = 2;
        ans[1] = 3;
        ans[n - 1] = 1;
        for (int i = 2; i < n - 1; i++) {
            ans[i] = n - i + 2;
        }

        for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == (n - 1)];
    }
}