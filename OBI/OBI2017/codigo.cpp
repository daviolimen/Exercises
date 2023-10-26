#include <bits/stdc++.h>
using namespace std;

int n;
set<string> prefix, suffix, sequence;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string atual, pref, suff; cin >> atual;
        if (sequence.find(atual) != sequence.end()) {
            cout << atual << "\n";
            return 0;
        }
        sequence.insert(atual);

        for (int j = 0; j < 9; j++) {
            pref = "";
            suff = "";
            for (int k = 0; k <= j; k++) {
                pref.push_back(atual[k]);
            }
            for (int k = j + 1; k < 10; k++) {
                suff.push_back(atual[k]);
            }

            if ((suffix.find(pref) != suffix.end()) && (prefix.find(suff) != prefix.end())) {
                cout << atual << "\n";
                return 0;
            }

            prefix.insert(pref);
            suffix.insert(suff);
        }
    }

    cout << "ok\n";
    return 0;
}