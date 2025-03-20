#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n, x; cin >> n >> x;
        vector<int> arr(n, 0);
        int totalOr = 0;
        for (int i = 0; i < n; i++) {
            if ((x & i) == i) {
                arr[i] = i;
            }
            totalOr |= arr[i];
        }
        if (totalOr != x) arr[n - 1] = x;
        for (int i = 0; i < n; i++) cout << arr[i] << " \n"[i == (n - 1)];
    }
}