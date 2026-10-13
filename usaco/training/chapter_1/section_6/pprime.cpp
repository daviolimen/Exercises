/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: pprime
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x == 1) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

string s;
set<int> pals;

void search(int curr, int sz) {
    if (curr == sz) {
        string rev(s);
        reverse(rev.begin(), rev.end());
        pals.insert(stoi(s + rev));
        pals.insert(stoi(s + rev.substr(1)));
        return;
    }
    for (int i = (!curr) ? 1 : 0; i < 10; i++) {
        s.push_back('0' + i);
        search(curr + 1, sz);
        s.pop_back();
    }
}

int main() {
    ifstream cin ("pprime.in");
    ofstream cout ("pprime.out");
    int a, b; cin >> a >> b;
    search(0, 1);
    search(0, 2);
    search(0, 3);
    search(0, 4);
    auto l = pals.lower_bound(a), r = pals.upper_bound(b);
    vector<int> ans;
    for (auto it = l; it != r; it++) if (isPrime(*it)) ans.push_back(*it);
    for (auto x : ans) cout << x << "\n";
    return 0;
}