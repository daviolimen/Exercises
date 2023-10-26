#include <bits/stdc++.h>
using namespace std;

long long patterns(int n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        return (patterns(n - 1) + patterns(n - 2));
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while (n != 0) {
        printf("%lld\n", (patterns(n)));
        scanf("%d", &n);
    }
}