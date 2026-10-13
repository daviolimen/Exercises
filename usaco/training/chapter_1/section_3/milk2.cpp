/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: milk2
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin ("milk2.in");
    ofstream cout ("milk2.out");
    int n; cin >> n;
    int milkStart = INT_MAX, milkEnd = -1;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        milkStart = min(milkStart, a);
        milkEnd = max(milkEnd, b);
        mp[a]++;
        mp[b]--;
    }


    int ctr = 0, curr1 = 0, curr2 = 0, ans1 = 0, ans2 = 0;
    for (int i = milkStart; i < milkEnd; i++) {
        ctr += mp[i];
        ans1 = max(ans1, curr1);
        ans2 = max(ans2, curr2);
        if (ctr > 0) {
            curr2 = 0;
            curr1++;
        } else {
            curr1 = 0;
            curr2++;
        }
    }
    ans1 = max(ans1, curr1);
    ans2 = max(ans2, curr2);


    cout << ans1 << " " << ans2 << "\n";

    return 0;
}