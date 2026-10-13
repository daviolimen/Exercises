#include <bits/stdc++.h>
using namespace std;

int countDivisors(int x) {
    int res = 0;
    for (int i = 1; i * i <= x; i++) {
        if ((x % i) == 0) {
            if (i * i == x) res++;
            else res += 2;
        }
    }
    return res;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        cout << countDivisors(x) << "\n";
    }
}