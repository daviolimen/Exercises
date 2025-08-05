#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    int mx = 0, cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (mx >= a[i]) cnt++;
        mx = max(mx, a[i]);
    }
    cout << cnt << "\n";
}