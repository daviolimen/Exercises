/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: dualpal
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

bool testString(int num) {
    int ctr = 0;
    for (int b = 2; b <= 10; b++) {
        string conv;
        int cpy = num;
        while (cpy > 0) {
            conv.push_back('0' + (cpy % b));
            cpy /= b;
        }
        if (isPalindrome(conv)) ctr++;
    }
    return ctr >= 2;
}

int main() {
    ifstream cin ("dualpal.in");
    ofstream cout ("dualpal.out");

    int n, s; cin >> n >> s;

    int ctr = 0;

    vector<int> ans;

    for (int i = s + 1;; i++) {
        if (testString(i)) {
            ans.push_back(i);
            ctr++;
        }
        if (ctr >= n) break;
    }

    for (int i = 0; i < n; i++) cout << ans[i] << "\n";

    return 0;
}