#include <bits/stdc++.h>
using namespace std;

int main() {
    int d1, h1, m1, d2, h2, m2;
    scanf("%d%d%d%d%d%d", &d1, &h1, &m1, &d2, &h2, &m2);
    int ans = (d2 - d1) * 86400 + (h2 - h1) * 3600 + (m2 - m1) * 60;
    printf("%d\n", ans);
}