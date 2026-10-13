#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> occ(10, 0);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            occ[x]++;
            if ((!ans) && (occ[0] >= 3) && (occ[2] >= 2) && (occ[1] >= 1) && (occ[3] >= 1) && (occ[5] >= 1)) {
                ans = i + 1;
            }
        }

        cout << ans << "\n";
    }
}