#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

string t, p;
int n, a[MAXN];

bool check(int x) {
    set<int> st;
    for (int i = 0; i < x; i++) st.insert(a[i]);

    string cpy;
    for (int i = 0; i < t.size(); i++) {
        if (st.find(i) != st.end()) continue;
        cpy.push_back(t[i]);
    }

    int curr = 0;

    for (auto c : cpy) {
        if (c == p[curr]) curr++;
        if (curr == p.size()) break;
    }

    return (curr == p.size());
}

int main() {
    cin >> t >> p;
    for (int i = 0; i < t.size(); i++) {
        cin >> a[i];
        a[i]--;
    }

    int l = 0, r = 200000;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (check(m)) l = m;
        else r = m;
    }

    cout << l << "\n";
}