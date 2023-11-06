#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int n, k, arr[MAXN];

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];

    multiset<int> st;
    for (int i = 0; i < k; i++) st.insert(arr[i]);

    auto it = st.begin();
    advance(it, (int) ceil(k / 2) - 1);

    cout << *it << " ";

    for (int i = k; i < n; i++) {
        st.insert(arr[i]);
        st.erase(st.find(arr[i - k]));

        auto it = st.begin();
        advance(it, (int) ceil(k / 2) - 1);

        cout << *it << " \n"[i == (n - 1)];
    }
}