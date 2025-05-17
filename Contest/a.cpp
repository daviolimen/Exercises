#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        int soma = 0;
        for (int i = 1; i <= n; i++) soma += abs(n - i + 1 - i);
        cout << 1 + soma / 2 << "\n";
    }
}