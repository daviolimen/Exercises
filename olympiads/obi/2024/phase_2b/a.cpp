#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string seq; cin >> seq;
    long long ans = 1;
    for (auto c : seq) {
        if (c == 'E') ans = ans * 2;
        else ans = ans * 2 + 1;
    }
    cout << ans << "\n";
}