#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int n;
unordered_map<string, string> pai;
unordered_map<string, int> peso, qtd;
unordered_set<string> used;

string find(string x) {
    if (pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(string x, string y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (peso[x] < peso[y]) {
        pai[x] = y;
        qtd[y] += qtd[x];
    } else if (peso[y] < peso[x]) {
        pai[y] = x;
        qtd[x] += qtd[y];
    } else {
        pai[y] = x;
        peso[x]++;
        qtd[x] += qtd[y];
    }
}

int main() {
    int tt; cin >> tt;
    while (tt--) {
        pai.clear();
        peso.clear();
        qtd.clear();
        used.clear();

        cin >> n;
        for (int i = 0; i < n; i++) {
            string a, b;
            cin >> a >> b;
            if (used.find(a) == used.end()) {
                pai[a] = a;
                peso[a] = 0;
                qtd[a] = 1;
                used.insert(a);
            }
            if (used.find(b) == used.end()) {
                pai[b] = b;
                peso[b] = 0;
                qtd[b] = 1;
                used.insert(b);
            }
            join(a, b);
            cout << qtd[find(a)] << "\n";
        }
    }
}