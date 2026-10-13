#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int e, s, l; cin >> e >> s >> l;
    cout << min(abs(e-s) + abs(s-l) + abs(l-e), abs(e-l) + abs(l-s) + abs(s-e)) << "\n";
}