#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    bool ans = 0;

    for (int i = n / 3; i >= 1; i--) {
        if (n % i) continue;
        for (int j = 0; j < i; j++) {
            bool ansFound = 1;
            for (int k = j; k < n; k += i) {
                if (!arr[k]) {
                    ansFound = 0;
                    break;
                }
            }
            if (ansFound) {
                ans = 1;
                break;
            }
        }
        if (ans) break;
    }

    cout << ((ans) ? "YES\n" : "NO\n");
}