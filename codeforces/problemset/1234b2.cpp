#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    list<int> ls;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (ls.size() < k) {
            if (st.find(x) == st.end()) {
                ls.push_front(x);
                st.insert(x);
            }
        } else {
            if (st.find(x) == st.end()) {
                st.erase(ls.back());
                ls.pop_back();
                ls.push_front(x);
                st.insert(x);
            }
        }
    }

    cout << ls.size() << "\n";
    for (auto it = ls.begin(); it != ls.end(); it++) {
        cout << *it << " ";
    }
    cout << "\n";
}