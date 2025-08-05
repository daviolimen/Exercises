#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int a, b, c ,d; cin >> a >> b >> c >> d;
    int curr = c;
    bool ok = 0;
    while (true) {
        if (curr >= a && curr <= b) {
            ok = 1;
            break;
        }
        if (curr < 0) break;
        curr -= d;
    }
    cout << ((ok) ? "S\n" : "N\n");
}