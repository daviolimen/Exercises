#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    char A[10001];
    char B[10001];
    for (int ctr = 0; ctr < T; ctr++) {
        scanf("%s %s", A, B);
        int ans = 0;
        for (size_t i = 0; i < strlen(A); i++) {
            char a = A[i];
            char b = B[i];
            int temp = b - a;
            if (temp >= 0) {
                ans += temp;
            } else {
                ans += 26 + temp;
            }
        }
        printf("%d\n", ans);
    }
}