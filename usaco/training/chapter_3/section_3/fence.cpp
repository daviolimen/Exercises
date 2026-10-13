/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: fence
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int F, deg[501], mat[501][501];
vector<int> ans;

void findCircuit(int u) {
    for (int i = 1; i <= 500; i++) {
        if (!mat[u][i]) continue;
        mat[u][i]--;
        mat[i][u]--;
        findCircuit(i);
    }

    ans.push_back(u);
}

int main() {
    ifstream cin ("fence.in");
    ofstream cout ("fence.out");
    cin >> F;
    for (int i = 0; i < F; i++) {
        int a, b; cin >> a >> b;
        mat[a][b]++;
        mat[b][a]++;
        deg[a]++;
        deg[b]++;
    }

    int start = -1;

    for (int i = 1; i <= 500; i++) {
        if (deg[i] & 1) {
            start = i;
            break;
        }
    }

    if (start == -1) {
        for (int i = 1; i <= 500; i++) {
            if (deg[i] > 0) {
                start = i;
                break;
            }
        }
    }

    findCircuit(start);
    reverse(ans.begin(), ans.end());

    for (auto x : ans) cout << x << "\n";
}