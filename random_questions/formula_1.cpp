#include <bits/stdc++.h>
using namespace std;

int main() {
    int g, p, a, s, k;
    scanf("%d%d", &g, &p);
    while (g != 0) {
        int corridas[g][p];
        for (int i = 0; i < g; i++) {
            for (int j = 0; j < p; j++) {
                scanf("%d", &a);
                corridas[i][j] = a;
            }
        }
        scanf("%d", &s);
        for (int i = 0; i < s; i++) {
            scanf("%d", &k);
            int pontos[p];
            int pontuacao[p];
            memset(pontos, 0, sizeof(int) * p);
            memset(pontuacao, 0, sizeof(int) * p);
            for (int j = 0; j < k; j++) {
                scanf("%d", &a);
                pontuacao[j] = a;
            }
            for (int j = 0; j < g; j++) {
                for (int l = 0; l < p; l++) {
                    pontos[l] += pontuacao[corridas[j][l] - 1];
                }
            }
            int best = 0;
            vector<int> vencedores;
            for (int i = 0; i < p; i++) {
                if (pontos[i] > best) {
                    best = pontos[i];
                    vencedores.clear();
                    vencedores.push_back(i + 1);
                } else if (pontos[i] == best) {
                    vencedores.push_back(i + 1);
                }
            }
            for (int i = 0; i < vencedores.size(); i++) {
                cout << vencedores[i] << " ";
            }
            cout << "\n";
        }
        scanf("%d%d", &g, &p);
    }
}