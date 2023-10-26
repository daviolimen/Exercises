#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10, MAXPERM = 40320;

int n, fact[MAXN];

int factorial(int x) {
    if (x == 0) return 1;
    if (fact[x] != 0) return fact[x];
    return fact[x] = x * factorial(x - 1);
}

int main() {
    cin >> n;
    unordered_set<string> st;

    for (int i = 1; i < factorial(n); i++) {
        string curr = "";
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            curr.push_back(c);
        }
        st.insert(curr);
    }

    string ans, perm = "";
    for (char i = '1'; i <= '0' + n; i++) perm.push_back(i);

    do {
        if (st.find(perm) == st.end()) {
            ans = perm;
            break;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    for (int i = 0; i < n; i++) {
        cout << perm[i] << " \n"[i == (n - 1)];
    }
}