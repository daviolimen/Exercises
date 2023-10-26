#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

int p, fat[MAXN];

int xpow(long long x, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = ((long long) (res % p) * (long long) (x % p)) % p;
        n >>= 1;
        x = ((x % p) * (x % p)) % p;
    }
    return res;
}

int factorial(int n) {
    if (n == 0) return 1;
    if (fat[n] != 0) return fat[n];

    return fat[n] = (n * factorial(n - 1)) % p;
}

int choose(int n, int k) {
    return (((factorial(n) * xpow(factorial(k), p-2)) % p) * xpow(factorial(n-k), p-2) ) % p;
}