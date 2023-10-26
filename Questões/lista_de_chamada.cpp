#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k; cin.ignore();
    vector<string> v;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s; cin.ignore();
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    cout << v[k - 1] << "\n";
}