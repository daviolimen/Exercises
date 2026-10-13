#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void getPerms(string s) {
    ans.push_back(s);
    if (next_permutation(s.begin(), s.end())) {
        getPerms(s);
    } else {
        return;
    }
}

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    getPerms(s);
    cout << ans.size() << "\n";
    for (auto str : ans) {
        cout << str << "\n";
    }
}