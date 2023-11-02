#include <bits/stdc++.h>
using namespace std;

#define MAXN 50000

int n, arr[MAXN];

bool check(int r) {
    
}

int bsearch() {
    int ini = 0, fim = n, meio, ans;
    while (ini <= fim) {
        meio = (ini + fim) >> 1;
        if (check(meio)) {
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
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);


}