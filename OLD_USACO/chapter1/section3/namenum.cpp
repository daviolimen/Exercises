/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: namenum
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>

using namespace std;

int n;
string curr, brand, letras = "      ABCDEFGHIJKLMNOPRSTUVWXY";
set<string> st;
vector<string> words, ans;

void search(int size) {
    if (size == n) {
        if (st.find(curr) != st.end()) ans.push_back(curr);
        return;
    }
    int x = brand[size] - '0';
    for (int i = x * 3; i < x * 3 + 3; i++) {
        curr.push_back(letras[i]);
        search(size + 1);
        curr.pop_back();
    }
}

int main() {
    ifstream dict ("dict.txt");
    ifstream cin ("namenum.in");
    ofstream cout ("namenum.out");

    string x;
    while (dict >> x) st.insert(x);

    cin >> brand;
    n = brand.size();
    search(0);

    for (auto s : words) {
        if (st.find(s) == st.end()) continue;
        ans.push_back(s);
    }

    for (auto s : ans) cout << s << "\n";
    if (ans.empty()) cout << "NONE\n";

    return 0;
}