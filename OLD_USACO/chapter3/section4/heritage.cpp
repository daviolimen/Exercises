/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: heritage
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

string inor, preor;
int n, idx, pos[30];

string ans;

void search(int l, int r) {
    int curr = pos[preor[idx] - 'A'];
    if (curr - 1 >= l) {
        idx++;
        search(l, curr - 1);
    }
    if (curr + 1 <= r) {
        idx++;
        search(curr + 1, r);
    }
    ans.push_back(inor[curr]);
}

int main() {
    ifstream cin ("heritage.in");
    ofstream cout ("heritage.out");
    cin >> inor >> preor;
    n = inor.size();
    for (int i = 0; i < n; i++) {
        pos[inor[i] - 'A'] = i;
    }
    search(0, n - 1);
    cout << ans << "\n";
    return 0;
}