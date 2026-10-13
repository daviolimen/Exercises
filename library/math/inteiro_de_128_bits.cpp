#include <bits/stdc++.h>
using namespace std;

void read(__uint128_t &x) {
    char c = getchar();
    while ((c >= '0') && (c <= '9')) {
        x = x * 10 + (c - '0');
        c = getchar();
    }
}

void print(__uint128_t x) {
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    __uint128_t a = 0, b = 0, m = 0;
    read(a);
    read(b);
    read(m);
    __uint128_t res = ((a % m) * (b % m)) % m;
    print(res);
}