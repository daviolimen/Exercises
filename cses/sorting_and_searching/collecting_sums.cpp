#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int n;
unordered_map<int, int> mp;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        mp[a] = i;
    }

    int last = 0, ctr = 1;

    for (int i = 1; i <= n; i++) {
        if (mp[i] > last) {
            last = mp[i];
        } else {
            ctr++;
            last = mp[i];
        }
    }

    cout << ctr << "\n";
}