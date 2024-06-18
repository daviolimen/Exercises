#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;

int arr[MAXN];

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            if (i < n) mx = max(mx, arr[i]);
        }
        cout << (mx + arr[n]) << "\n";
    }
}