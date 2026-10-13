#include <bits/stdc++.h>
using namespace std;

int main() {
    int e, d; cin >> e >> d;
    cout << ((e > d) ? (e + d) : (2 * (d - e))) << "\n";
}