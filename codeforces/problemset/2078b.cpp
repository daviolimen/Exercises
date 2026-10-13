#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        if (k % 2) {
            for (int i = 1; i < n; i++) cout << n << " ";
            cout << n - 1 << "\n";
        } else {
            for (int i = 1; i < (n - 1); i++) cout << n - 1 << " ";
            cout << n << " " << n - 1 << "\n";
        }
    }
}