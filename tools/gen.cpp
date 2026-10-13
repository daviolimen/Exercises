// Gerador de testes aleatórios para o stress test.
// Uso: ./gen <seed>   (o stress.sh passa o número do teste como seed)
//
// Copie este arquivo para a pasta do problema e ajuste main() ao formato
// de entrada. Mantenha os testes PEQUENOS: o brute precisa rodar rápido
// e um contraexemplo pequeno é muito mais fácil de depurar.
#include <bits/stdc++.h>
using namespace std;

mt19937 rng;

long long rnd(long long l, long long r) {  // inteiro uniforme em [l, r]
    return uniform_int_distribution<long long>(l, r)(rng);
}

int main(int argc, char* argv[]) {
    rng.seed(argc > 1 ? atoi(argv[1]) : 0);

    // Exemplo: 1 teste com um array de n elementos.
    int t = 1;
    cout << t << '\n';
    while (t--) {
        int n = rnd(1, 8);
        cout << n << '\n';
        for (int i = 0; i < n; i++) cout << rnd(1, 10) << " \n"[i == n - 1];
    }
    return 0;
}
