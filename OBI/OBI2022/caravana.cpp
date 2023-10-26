#include <bits/stdc++.h>
using namespace std;

#define MAXN 1001

int n, pesos[MAXN];

int main() {
    cin >> n;
    int peso = 0;
    for (int i = 0; i < n; i++) {
        cin >> pesos[i];
        peso += pesos[i];
    }
    peso /= n;
    for (int i = 0; i < n; i++) {
        cout << peso - pesos[i] << "\n";
    }
}