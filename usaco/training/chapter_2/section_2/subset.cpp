/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: subset
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin ("subset.in");
    ofstream cout ("subset.out");

    int n; cin >> n;
    int somaTotal = n * (n + 1) / 2;
    if (somaTotal % 2) {
        cout << "0\n";
        return 0;
    }

    int somaCada = somaTotal / 2;

    int tam1 = n / 2, tam2 = n - tam1;
    vector<int> v1, v2;
    for (int i = 1; i <= tam1; i++) v1.push_back(i);
    for (int i = tam1 + 1; i <= n; i++) v2.push_back(i);


    map<int, int> mp1, mp2;
    for (int mask = 0; mask < (1 << tam1); mask++) {
        int soma = 0;
        for (int j = 0; j < tam1; j++) {
            if (!(mask & (1 << j))) continue;
            soma += v1[j];
        }
        mp1[soma]++;
    }

    for (int mask = 0; mask < (1 << tam2); mask++) {
        int soma = 0;
        for (int j = 0; j < tam2; j++) {
            if (!(mask & (1 << j))) continue;
            soma += v2[j];
        }
        mp2[soma]++;
    }

    long long ans = 0;

    for (auto x : mp1) {
        if (mp2.find(somaCada - x.first) == mp2.end()) continue;
        ans += (long long) x.second * mp2[somaCada - x.first];
    }

    cout << ans / 2 << "\n";
    return 0;
}