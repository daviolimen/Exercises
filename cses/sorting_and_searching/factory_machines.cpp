#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int n, t, arr[MAXN];

bool check(long long x) {
    long long ctr = 0;
    for (int i = 0; i < n; i++) {
        ctr += (x / (long long) arr[i]);
        if (ctr >= t) return true;
    }
    return (ctr >= t);
}

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long l = 0, r = 1;
    while (!check(r)) r *= 2;

    while (r - l > 1) {
        long long m = (r + l) >> 1;
        if (check(m)) r = m;
        else l = m;
    }

    cout << r << "\n";
}