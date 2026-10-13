/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: rockers
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int N, T, M, pesos[20], used[20], ctr, ans, best[20];
vector<int> resposta[20], atual[20];

void fillBag(int item, int bagMin, int bagMax) {
    ans = max(ans, ctr);
    if (item == N) return;

    for (int i = bagMin; i <= bagMax; i++) {
        if (used[i] + pesos[item] > T) continue;
        used[i] += pesos[item];
        ctr++;
        fillBag(item + 1, i, (i == bagMax) ? min(M - 1, bagMax + 1) : bagMax);
        ctr--;
        used[i] -= pesos[item];
    }
    fillBag(item + 1, bagMin, bagMax);
}

int main() {
    ifstream cin ("rockers.in");
    ofstream cout ("rockers.out");
    cin >> N >> T >> M;
    for (int i = 0; i < N; i++) cin >> pesos[i];
    fillBag(0, 0, 0);
    cout << ans << "\n";
    return 0;
}