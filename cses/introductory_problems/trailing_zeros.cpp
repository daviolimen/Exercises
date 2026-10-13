#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 5; i <= n; i *= 5) {
        res += (int) n / i;
    }
    cout << res << "\n";
}