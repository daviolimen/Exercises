#include <bits/stdc++.h>
using namespace std;

string proxBusca(string s) {
    bool ok = false;

    for (int i = s.size() - 1; i >= 0; i--) {
        
        if (s[i] == '9') {
            s[i] = '0';
            continue;
        } else {
            s[i]++;
            ok = true;
            break;
        }
    }

    return ok ? s : ("1" + s);
}

int main() {
    int n; cin >> n;
    string digitos;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        digitos += c;
    }

    for (int tam = 1; tam <= n; tam++) {
        string ini, busca;

        for (int i = 0; i < tam; i++) {
            ini += digitos[i];
        }

        busca = ini;

        string atual;

        for (int i = 0; i < n; i++) {
            atual += digitos[i];

            if (atual == busca) {
                atual = "";
                busca = proxBusca(busca);
            }
        }

        if (atual == "") {
            cout << ini << "\n";
            return 0;
        }
    }
}