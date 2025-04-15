#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int n = s.size();
    bool res = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] != s[n - i - 1]) {
            res = 0;
            break;
        }
    }
    return res;
}

int main() {
    int ans = 0;
    for (int i = 1; i < 1000000; i++) {
        int cpy = i;
        string base10, base2;
        while (cpy > 0) {
            base10.push_back('0' + (cpy % 10));
            cpy /= 10;
        }

        cpy = i;
        while (cpy > 0) {
            base2.push_back('0' + (cpy % 2));
            cpy /= 2;
        }

        if (isPalindrome(base10) && isPalindrome(base2)) ans += i;
    }

    cout << ans << "\n";
}