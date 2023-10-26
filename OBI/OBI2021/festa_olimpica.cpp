#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, ops[5000];
vector<ll> ans;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> ops[i];

    for (int i = 0; i <= min(n, (ll) 10000); i++) ans.push_back(i);

    for (int i = (m - 1); i >= 0; i--) {
        for (int j = 1; j < ans.size(); j++) {
            ans[j] += (ans[j] - 1) / (ops[i] - 1);
        }
        while (ans.back() > n) ans.pop_back();
    }

    for (auto it = ans.begin() + 1; it != ans.end(); it++) cout << *it << "\n";
}