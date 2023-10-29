#include <bits/stdc++.h>
using namespace std;

int n, ctr[26];

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b; cin >> a >> b;
        for (int i = 0; i < 26; i++) {
            ctr[i] += max(count(a.begin(), a.end(), (char) (i + 'a')), count(b.begin(), b.end(), (char) (i + 'a')));
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << ctr[i] << "\n";
    }
}