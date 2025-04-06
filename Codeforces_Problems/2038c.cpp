#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        map<int, int> mp;
        for (auto &x : a) {
            cin >> x;
            mp[x]++;
        }
        vector<int> twoOrMore;
        for (auto X : mp) {
            for (int i = 0; i < X.second / 2; i++) {
                twoOrMore.push_back(X.first);
            }
        }

        if (twoOrMore.size() < 4) {
            cout << "NO\n";
        } else {
            int x1 = twoOrMore[twoOrMore.size() - 1];
            int y1 = twoOrMore[twoOrMore.size() - 2];
            int x0 = twoOrMore[1];
            int y0 = twoOrMore[0];
            cout << "YES\n";
            cout << x0 << " " << y0 << " " << x0 << " " << y1 << " " << x1 << " " << y1 << " " << x1 << " " << y0 << "\n";
        }
    }
}