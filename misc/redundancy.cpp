#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    map<int, unsigned int> m;
    while (cin >> n) {
        m[n]++;
    }
    for (auto itr = m.begin(); itr != m.end(); itr++) {
        cout << (*itr).first << " " << (*itr).second << "\n";
    }
}