#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int x, n; cin >> x >> n;
    set<int> s = {0, x};
    multiset<int> ms = {x};
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        auto it1 = s.upper_bound(a);
        auto it2 = it1;
        it2--;
        ms.erase(ms.find(*it1 - *it2));
        ms.insert(*it1 - a);
        ms.insert(a - *it2);
        s.insert(a);
        cout << *(--(ms.end())) << " \n"[i == (n - 1)];
    }
}