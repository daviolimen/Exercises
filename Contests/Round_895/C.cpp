#include <bits/stdc++.h>
using namespace std;

int getDivisor(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return i;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int l, r, a = 0, b = 0;
        cin >> l >> r;
        for (int i = l; i <= r; i++) {
            if (getDivisor(i) != -1) {
                a = getDivisor(i);
                b = i - getDivisor(i);
                break;
            }
        }
        if ((a <= 0) || (b <= 0)) {
            cout << "-1\n";
        } else {
            cout << a << " " << b << "\n";
        }
    }
}