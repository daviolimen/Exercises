#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (auto &x : a) {
        cin >> x;
        mx = max(mx, x);
    }
    vector<vector<int>> mat(mx, vector<int>(n));
    for (int i = 0; i < mx; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j] > i) mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }

    for (int i = mx - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " \n"[j == (n - 1)];
        }
    }
}