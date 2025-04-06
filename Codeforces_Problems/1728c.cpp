#include <bits/stdc++.h>
using namespace std;

int digitalLog(int x) {
    int res = 0;
    while (x > 0) {
        res++;
        x /= 10;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        priority_queue<int> a, b;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a.push(x);
        }
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            b.push(x);
        }

        int ans = 0;

        while (!a.empty()) {
            if (a.top() == b.top()) {
                a.pop();
                b.pop();
                continue;
            } else if (a.top() > b.top()) {
                a.push(digitalLog(a.top()));
                a.pop();
                ans++;
            } else {
                b.push(digitalLog(b.top()));
                b.pop();
                ans++;
            }
        }

        cout << ans << "\n";
    }
}