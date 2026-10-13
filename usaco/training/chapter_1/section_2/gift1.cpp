/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream cout ("gift1.out");
    ifstream cin ("gift1.in");

    int np; cin >> np;
    vector<string> names;
    map<string, int> acc;

    for (int i = 0; i < np; i++) {
        string x; cin >> x;
        names.push_back(x);
        acc[x] = 0;
    }

    for (int i = 0; i < np; i++) {
        string name; cin >> name;
        int money, ng; cin >> money >> ng;
        if (ng == 0) {
            acc[name] += money;
            continue;
        }
        acc[name] -= money;
        acc[name] += money % ng;
        for (int j = 0; j < ng; j++) {
            string x; cin >> x;
            acc[x] += money / ng;
        }
    }

    for (auto s : names) {
        cout << s << " " << acc[s] << "\n";
    }

    return 0;
}