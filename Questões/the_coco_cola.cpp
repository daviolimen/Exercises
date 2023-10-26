#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while (n != 0) {
        if ((n % 2) == 0) {
            printf("%d\n", n / 2);
        } else {
            printf("%d\n", (n - 1) / 2);
        }
        scanf("%d", &n);
    }
}