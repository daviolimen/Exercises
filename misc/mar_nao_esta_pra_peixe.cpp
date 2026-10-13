#include <bits/stdc++.h>
using namespace std;

bool oceano[101][101];

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int xi, xf, yi, yf;
        scanf("%d%d%d%d", &xi, &xf, &yi, &yf);
        for (int j = yi; j < yf; j++) {
            for (int k = xi; k < xf; k++) {
                if (!oceano[j][k]) {
                    ans++;
                    oceano[j][k] = true;
                }
            }
        }
    }
    printf("%d\n", ans);
}