/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: contact
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

bool comp(const string &a, const string &b) {
    if (a.size() < b.size()) return 1;
    if (a.size() > b.size()) return 0;
    return a < b;
}

int main() {
    ifstream cin ("contact.in");
    ofstream cout ("contact.out");
    int a, b, n; cin >> a >> b >> n;
    string s;
    char c;
    while (cin >> c) {
        s.push_back(c);
    }

    map<string, int> mp;

    for (int i = 0; i < (int) s.size(); i++) {
        for (int j = a; j <= b; j++) {
            if (i - j + 1 < 0) continue;
            string sub = s.substr(i - j + 1, j);
            mp[sub]++;
        }
    }

    vector<vector<string>> freq(200100);

    for (auto x : mp) {
        freq[x.second].push_back(x.first);
    }

    for (int i = 0; i <= 200000; i++) sort(freq[i].begin(), freq[i].end(), comp);

    int ctr = 0;
    for (int i = 200000; (i > 0) && (ctr < n); i--) {
        if (freq[i].empty()) continue;
        if (ctr > 0) cout << "\n";
        cout << i;
        for (int j = 0; j < (int) freq[i].size(); j++) {
            if (j % 6 == 0) cout << "\n";
            else cout << " ";
            cout << freq[i][j];
        }
        ctr++;
    }
    cout << "\n";
    return 0;
}