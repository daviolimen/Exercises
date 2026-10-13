#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int x = m, ans = 0;
    vector<int> steps;
    steps.push_back(x);
    while (x > n) {
        x = (x + 1) / 2;
        steps.push_back(x);
    }

    for (auto it = steps.rbegin(); it != steps.rend(); it++) {
        if (n < *it) {
            n *= 2;
            ans++;
        }
        while (n > *it) {
            n--;
            ans++;
        }
    }

    cout << ans << "\n";
}