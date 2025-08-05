#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<char, char> cifra;
    bool ok = 1;
    for (int i = 0; i < n; i++) {
        string cur; cin >> cur;
        if (cifra.find(cur[0]) == cifra.end()) {
            cifra[cur[0]] = cur[3];
        } else {
            if (cifra[cur[0]] == cur[3]) continue;
            ok = 0;
        }
    }
    map<char, int> cnt;
    for (auto P : cifra) {
        cnt[P.second]++;
        if (cnt[P.second] > 1) ok = 0;
    }

    int m; cin >> m;
    cin.get();
    string text;
    for (int i = 0; i < m; i++) {
        string line; getline(cin, line);
        text += line + "\n";
    }
    for (int i = 0; i < text.size(); i++) {
        if (cifra.find(text[i]) == cifra.end()) continue;
        text[i] = cifra[text[i]];
    }
    if (!ok) {
        cout << "Erro\n";
        return 0;
    }
    cout << text;
}