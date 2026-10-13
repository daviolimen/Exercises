#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<vector<char>> mat(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }

        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            int pos = 0;
            for (int j = 0; j < i; j++) {
                if (mat[i][j] == '1') pos++;
            }
            for (int j = i + 1; j < n; j++) {
                if (mat[i][j] == '0') pos++;
            }
            ans[pos] = i;
        }

        for (auto x : ans) cout << x + 1 << " ";
        cout << "\n";
    }
}