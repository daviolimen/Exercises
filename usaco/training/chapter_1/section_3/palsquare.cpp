/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: palsquare
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) return 0;
    }
    return 1;
}

int main() {
    ifstream cin ("palsquare.in");
    ofstream cout ("palsquare.out");

    int b; cin >> b;

    vector<pair<string, string>> ans;

    for (int n = 1; n <= 300; n++) {
        string number;
        int cpy = n;
        while (cpy > 0) {
            int r = cpy % b;
            if (r >= 10) number.push_back('A' + r - 10);
            else number.push_back('0' + r);
            cpy /= b;
        }
        reverse(number.begin(), number.end());

        string converted;
        cpy = n * n;
        while (cpy > 0) {
            int r = cpy % b;
            if (r >= 10) converted.push_back('A' + r - 10);
            else converted.push_back('0' + r);
            cpy /= b;
        }

        if (isPalindrome(converted)) ans.emplace_back(number, converted);
    }

    for (auto X : ans) {
        cout << X.first << " " << X.second << "\n";
    }

    return 0;
}