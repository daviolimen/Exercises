#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, m, grau[MAXN];
vector<int> graph[MAXN], lista;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        grau[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (grau[i] == 0) lista.push_back(i);
    }

    int ini = 0;
    while (ini < (int) lista.size()) {
        int atual = lista[ini];
        ini++;

        for (auto v : graph[atual]) {
            grau[v]--;
            if (grau[v] == 0) lista.push_back(v);
        }
    }

    if ((int) lista.size() < n) cout << "Nao tem topoSort pra todos os vertices\n";
    else {
        for (int i = 0; i < (int) lista.size(); i++) cout << lista[i] << " \n"[i == lista.size() - 1];
    }
    return 0;
}