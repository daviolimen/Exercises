#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    long long sum = (n * (n + 1)) >> 1;
    cout << sum << "\n";
    if (sum % 2) {
        cout << "0\n";
        return 0;
    }

    long long des = sum >> 1;
}