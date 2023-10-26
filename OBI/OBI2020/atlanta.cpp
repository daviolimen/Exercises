#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, x = -1, y = -1; cin >> A >> B;
    bool solved = false;
    for (x = 1; x <= 1000000; x++) {
        y = (A + 4 - 2 * x) / 2;
        if ((x <= 2) || (y <= 2)) continue;
        if ((x - 2) * (y - 2) == B) {
            solved = true;
            break;
        }
    }
    if (solved) cout << x << " " << y << "\n";
    else cout << "-1 -1\n";
}