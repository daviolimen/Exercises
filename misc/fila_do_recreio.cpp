#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, P;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &M);
        int fila_i[M];
        int fila_f[M];
        for (int j = 0; j < M; j++) {
            scanf("%d", &P);
            fila_i[j] = P;
            fila_f[j] = P;
        }
        sort(fila_f, fila_f + M, greater<int>());
        int ans = 0;
        for (int j = 0; j < M; j++) {
            if (fila_i[j] == fila_f[j]) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}