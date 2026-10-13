#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(unsigned long long x) {
    for (int i = 2; i <= 1 + sqrt(x); i++) {
        if ((x % i) == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    unsigned long long n;
    scanf("%llu", &n);
    if (isPrime(n)) {
        printf("N\n");
    } else {
        printf("S\n");
    }
}