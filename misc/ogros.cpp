#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010
typedef long long ll;

int n, m;
ll f, faixas[MAXN], premios[MAXN];


int main() {
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        cin >> faixas[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> premios[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> f;
        int ans = upper_bound(faixas, faixas + n, f) - faixas - 1;
        cout << premios[ans] << " \n"[i==m];
    }
}