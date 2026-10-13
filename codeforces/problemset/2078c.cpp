// maximize a2

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(2 * n);
        for (auto &x : arr) cin >> x;
        sort(arr.begin(), arr.end());

        int soma1 = 0, soma2 = 0;
        for (int i = 0; i < n - 1; i++) soma1 += arr[i];
        for (int i = n - 1; i < 2 * n; i++) soma2 += arr[i];
        
        int ptr1 = n - 1, ptr2 = 0;
        for (int i = 1; i <= 2 * n + 1; i++) {
            if (i == 2) {
                cout << soma2 - soma1 << " ";
                continue;
            }
            if (i % 2) {
                cout << arr[ptr1++] << " ";
            } else {
                cout << arr[ptr2++] << " ";
            }
        }
        cout << "\n";
    }
}