/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: fracdec
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin ("fracdec.in");
    ofstream cout ("fracdec.out");
    int N, D; cin >> N >> D;
    int wholePart = N / D;
    N %= D;
    vector<int> fracPart, visited(D, -1);
    int idx = -1;
    while (true) {
        if (N == 0) break;
        if (visited[N] >= 0) {
            idx = visited[N];
            break;
        }
        visited[N] = fracPart.size();
        N *= 10;
        fracPart.push_back(N / D);
        N %= D;
    }

    string saida;
    if (wholePart == 0) saida.push_back('0');
    while (wholePart > 0) {
        saida.push_back('0' + (wholePart % 10));
        wholePart /= 10;
    }

    reverse(saida.begin(), saida.end());
    saida.push_back('.');

    if (fracPart.empty()) saida.push_back('0');
    else {
        for (int i = 0; i < (int) fracPart.size(); i++) {
            if (i == idx) saida.push_back('(');
            saida.push_back('0' + fracPart[i]);
        }
        if (idx != -1) saida.push_back(')');
    }

    for (int i = 0; i < saida.size(); i++) {
        if ((i > 0) && (i % 76 == 0)) cout << "\n";
        cout << saida[i];
    }
    cout << "\n";
    return 0;
}