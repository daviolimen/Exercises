#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        vector<vector<int>> inv(n, vector<int>(n, 0));
        vector<vector<int>> equ(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                inv[i][j] = inv[i][j - 1] + (arr[i] > arr[j]);
                equ[i][j] = equ[i][j - 1] + (arr[i] == arr[j]);
            }
        }

        int ans = INT_MIN, bestX, bestY;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int temp = inv[i][j] - (j - i - inv[i][j] - equ[i][j]);
                if (temp > ans) {
                    ans = temp;
                    bestX = i;
                    bestY = j;
                }
            }
        }

        cout << bestX + 1 << " " << bestY + 1 << "\n";
    }
}