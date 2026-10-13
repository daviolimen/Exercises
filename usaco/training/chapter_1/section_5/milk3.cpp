/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: milk3
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int cap[3];
bool state[21][21][21];
vector<int> ans;

void search(int curr[3]) {
    if (state[curr[0]][curr[1]][curr[2]]) return;
    state[curr[0]][curr[1]][curr[2]] = 1;
    if (!curr[0]) {
        ans.push_back(curr[2]);
    }

    for (int i = 0; i < 3; i++) {
        if (!curr[i]) continue;
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            int temp[3] = {curr[0], curr[1], curr[2]};
            temp[j] += temp[i];
            temp[i] = 0;
            if (temp[j] > cap[j]) {
                temp[i] = temp[j] - cap[j];
                temp[j] = cap[j];
            }
            search(temp);
        }
    }
}

int main() {
    ifstream cin ("milk3.in");
    ofstream cout ("milk3.out");
    for (int i = 0; i < 3; i++) cin >> cap[i];
    int start[3] = {0, 0, cap[2]};
    search(start);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int) ans.size(); i++) cout << ans[i] << " \n"[i == (int) ans.size() - 1];
    return 0;
}