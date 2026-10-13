#include <bits/stdc++.h>
using namespace std;

long long cycle_length(long long n) {
    long long counter = 0;
    while (true) {
        counter++;
        if (n == 1) {
            break;
        }
        if ((n % 2) == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }
    return counter;
}

int main() {
    long long a, b, max;
    while (cin >> a >> b) {
        max = 0;
        for (int i = a; i <= b; i++) {
            long long x = cycle_length(i);
            if (x > max) {
                max = x;
            }
        }
        cout << a << " " << b << " " << max << "\n";
    }
}