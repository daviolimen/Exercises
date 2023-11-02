#include <bits/stdc++.h>
using namespace std;

int n, x, y;

bool check(int a) {
    int ctr = 0;
    if (a >= min(x, y)) {
        a -= min(x, y);
        ctr++;
    }

    ctr += (a / x);
    ctr += (a / y);

    return (ctr >= n);
}

int main() {
    cin >> n >> x >> y;

    int l = 0, r = (int) 2e9 + 10;
    while (r - l > 1) {
        int m = l + ((r - l) >> 1);
        if (check(m)) r = m;
        else l = m;
    }

    cout << r << "\n";
}