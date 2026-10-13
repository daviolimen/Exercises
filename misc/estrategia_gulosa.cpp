#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, m = 0;
    scanf("%d", &v);
    while (v != 0) {
        if (v >= 100) {
            v -= 100;
            m++;
        } else if (v >= 50) {
            v -= 50;
            m++;
        } else if (v >= 25) {
            v -= 25;
            m++;
        } else if (v >= 10) {
            v -= 10;
            m++;
        } else if (v >= 5) {
            v -= 5;
            m++;
        } else if (v >= 1) {
            v -= 1;
            m++;
        }
    }
    printf("%d\n", m);
}