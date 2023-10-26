#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
    cin >> a >> b;
    a %= 3;
    b %= 3;
    if (a == b) b = (a + 1) % 3;
    if (a + b == 1) cout << "2\n";
    else if (a + b == 2) cout << "1\n";
    else cout << "0\n";
}