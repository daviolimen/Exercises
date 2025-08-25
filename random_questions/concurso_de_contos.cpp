#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, L, C;
    string palavra;
    while (cin >> N >> L >> C) {
        int linha = 0;
        int linhas = 1;
        for (int i = 1; i <= N; i++) {
            cin >> palavra;
            int l = palavra.length();
            if (linha + l <= C) {
                linha += l + 1;
            } else {
                linha = l + 1;
                linhas++;
            }
        }
        int ans = ceil((float) linhas / (float) L);
        cout << ans << "\n";
    }
}