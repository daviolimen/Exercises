#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int n, room[MAXN];
tuple<int, int, int> inp[MAXN];
set<pair<int, int>> st;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        auto &[a, b, c] = inp[i];
        cin >> a >> b;
        c = i;
    }

    sort(inp, inp + n);

    auto[a, b, idx] = inp[0];

    st.emplace(b, 1);
    room[idx] = 1;

    int curr_room = 2;

    for (int i = 1; i < n; i++) {
        auto [a, b, idx] = inp[i];
        auto it = st.begin();
        if ((it->first) < a) {
            int r = it->second;
            st.erase(it);
            st.emplace(b, r);
            room[idx] = r;
        } else {
            st.emplace(b, curr_room);
            room[idx] = curr_room++;
        }
    }

    cout << (curr_room - 1) << "\n";

    for (int i = 0; i < n; i++) {
        cout << room[i] << " \n"[i == (n - 1)];
    }
}