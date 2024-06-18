#include <bits/stdc++.h>
using namespace std;

int n;
vector<char> arr;

bool isOp(char c) {
    if ((c < '0') || (c > '9')) return 1;
    return 0;
}

int calcArray(int l, vector<char> v) {

}

int main() {
    string inp; getline(cin, inp);

    for (auto c : inp) {
        if (('*' <= c) && (c <= '9')) arr.push_back(c);
    }

    n = arr.size();

    sort(arr.begin(), arr.end());

    int res = 0;

    do {
        res = max(res, calcArray(n, arr));
    } while (next_permutation(arr.begin(), arr.end()));

    cout << res << "\n";
}