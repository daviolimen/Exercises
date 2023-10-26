#include <bits/stdc++.h>
using namespace std;

int n, m;
multiset<int> tickets;

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        tickets.insert(a);
    }
    for (int i = 0; i < m; i++) {
        cin >> a;
        auto it = tickets.upper_bound(a);
        if (it == tickets.begin()) {
            cout << "-1\n";
        } else {
            cout << *(--it) << "\n";
            tickets.erase(it);
        }
    }
}