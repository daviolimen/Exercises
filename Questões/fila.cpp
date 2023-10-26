#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    vector<int> fila;
    set<int> saidas;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        fila.push_back(a);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a;
        scanf("%d", &a);
        saidas.insert(a);
    }
    for (int i = 0; i < n; i++) {
        if (saidas.find(fila[i]) == saidas.end()) {
            cout << fila[i] << " ";
        }
    }
}