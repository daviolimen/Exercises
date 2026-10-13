#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, x; cin >> n >> x;
        int soma = 0;
        for (int i = 0; i < n; i++) {
            int num; cin >> num;
            soma += num;
        }
        if (soma % n == 0) {
            if (soma / n == x) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "NO\n";
        }
    }
}