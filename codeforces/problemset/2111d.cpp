#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> arr(m);
        for (int i = 0; i < m; i++) cin >> arr[i];

        sort(arr.begin(), arr.end());

        vector<vector<int>> rooms(n, vector<int>(6));

        int cur = 0, idx = 0;

        while (cur < n - 1) {
            for (int j = 0; j < 6; j++) {
                int par, impar;
                if (j % 2) {
                    par = arr[idx];
                    impar = arr[m - idx - 1];
                } else {
                    par = arr[m - idx - 1];
                    impar = arr[idx];
                }

                rooms[cur][j] = par;
                rooms[cur + 1][j] = impar;
            }
            cur += 2;
            idx++;
        }

        if (cur == n - 1) {
            for (int j = 0; j < 6; j++) {
                rooms[cur][j] = (j % 2) ? arr[idx] : arr[m - idx - 1];
            }
        }

        for (auto V : rooms) {
            for (auto x : V) cout << x << " ";
            cout << "\n";
        }
    }
}