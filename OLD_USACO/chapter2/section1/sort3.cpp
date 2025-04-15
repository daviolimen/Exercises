// OBS: dava pra fazer em O(n) simplesmente contando quantos errados tem em cada região sem
// realmente fazer os swaps

/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: sort3
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int n, ans, qnt[4], pref[4], arr[1000];

int getRegion(int idx) {
    if (idx < pref[1]) return 1;
    if (idx < pref[2]) return 2;
    return 3;
}

void solve(int a, int b) {
    for (int i = pref[a - 1]; i < pref[a]; i++) {
        for (int j = pref[b - 1]; j < pref[b]; j++) {
            if ((arr[i] == b) && (arr[j] == a)) {
                ans++;
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    ifstream cin ("sort3.in");
    ofstream cout ("sort3.out");
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        qnt[arr[i]]++;
    }

    for (int i = 1; i < 4; i++) pref[i] = pref[i - 1] + qnt[i];
    solve(1, 2);
    solve(1, 3);
    solve(2, 3);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == getRegion(i)) continue;
        cnt++;
    }

    ans += cnt / 3 * 2;
    cout << ans << "\n";

    return 0;
}