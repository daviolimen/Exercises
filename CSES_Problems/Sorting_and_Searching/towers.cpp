#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int n;
vector<int> arr;

int bsearch(int k) {
    int ini = 0, fim = arr.size() - 1, meio, ans = -1;
    while (ini <= fim) {
        meio = (ini + fim) >> 1;
        if (arr[meio] > k) {
            ans = meio;
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k, pos; cin >> k;
        pos = bsearch(k);
        if (pos == -1) {
            arr.push_back(k);
        } else {
            arr[pos] = k;
        }
    }

    cout << arr.size() << "\n";
}