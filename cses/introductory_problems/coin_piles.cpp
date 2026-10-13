#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        if ((a > 2 * b) || (b > 2 * a)) cout << "NO\n";
        else if (((a % 3 == 2) && (b % 3 == 1)) || ((a % 3 == 1) && (b % 3 == 2)) || ((a % 3 == 0) && (b % 3 == 0))) cout << "YES\n";
        else cout << "NO\n";
    }
}