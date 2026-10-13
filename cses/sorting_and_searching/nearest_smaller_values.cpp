#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    stack<pair<int, int>> st;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        while ((!st.empty()) && (st.top().first >= a)) {
            st.pop();
        }
        if (st.empty()) {
            cout << "0" << " \n"[i == n];
        } else {
            cout << st.top().second << " \n"[i == n];
        }
        st.emplace(a, i);
    }
}