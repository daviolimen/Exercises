#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        int mnIdx = -1, mn = INT_MAX;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            if (arr[i] < mn) {
                mn = arr[i];
                mnIdx = i;
            }
        }

        cout << n - 1 << "\n";
        for (int i = mnIdx - 1; i >= 1; i--) {
            if ((mnIdx - i) % 2) {
                cout << i << " " << i + 1 << " " << mn + 1 << " " << mn << "\n";
            } else {
                cout << mnIdx << " " << i << " " << mn << " " << mn << "\n";
            }
        }

        for (int i = mnIdx + 1; i <= n; i++) {
            if ((i - mnIdx) % 2) {
                cout << i << " " << i - 1 << " " << mn + 1 << " " << mn << "\n";
            } else {
                cout << mnIdx << " " << i << " " << mn << " " << mn << "\n";
            }
        }
    }
}