#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        string cur; cin >> cur;
        int zeros = 0, ones = 0;
        for (auto x : cur) {
            if (x == '0') zeros++;
            else ones++;
        }

        int mx = n / 2;
        if (zeros % 2) mx--;
        int mn = abs(zeros - ones) / 2;
        if ((k >= mn) && (k <= mx) && ((k % 2) == (mx % 2))) cout << "YES\n";
        else cout << "NO\n";
    }
}