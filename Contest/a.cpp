#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        if (n % 2 == 0) {
            cout << "-1\n";
            continue;
        }
        cout << n << " ";
        for (int i = 1; i < n; i++) cout << i << " \n"[i == n - 1];
    }
}