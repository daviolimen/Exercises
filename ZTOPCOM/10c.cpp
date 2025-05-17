#include <bits/stdc++.h>
using namespace std;

int cons[32][13][202];

int numDias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool biss(int a) {
    if (a % 400 == 0) return 1;
    if (a % 100 == 0) return 0;
    if (a % 4) return 0;
    return 1;
}

tuple<int, int, int> proxDia(int d, int m, int a) {
    int dias = numDias[m];
    if ((m == 2) && (biss(a + 1900))) dias++;
    if (d == dias && m == 12) return tuple<int, int, int>(1, 1, a + 1);
    if (d == dias) return tuple<int, int, int>(1, m + 1, a);
    return tuple<int, int, int>(d + 1, m, a);
}

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    while (true) {
        int n; cin >> n;
        if (!n) break;
        memset(cons, -1, sizeof(cons));
        for (int i = 0; i < n; i++) {
            int d, m, a, c; cin >> d >> m >> a >> c;
            cons[d][m][a - 1900] = c;
        }
        int qnt = 0, soma = 0;
        for (int d = 1; d < 32; d++) {
            for (int m = 1; m < 13; m++) {
                for (int a = 0; a <= 200; a++) {
                    if (cons[d][m][a] == -1) continue;
                    auto [d2, m2, a2] = proxDia(d, m, a);
                    if (cons[d2][m2][a2] == -1) continue;
                    qnt++;
                    soma += cons[d2][m2][a2] - cons[d][m][a];
                }
            }
        }

        cout << qnt << " " << soma << "\n";
    }
}