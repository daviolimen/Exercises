#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, l, h, arr[MAXN], marcas[MAXN], prefixSums[MAXN], prefixMarcas[MAXN];

int main() {
    cin >> n >> l >> h;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) cin >> marcas[i];

    for (int i = 1; i <= n; i++) {
        prefixSums[i] = prefixSums[i - 1] + arr[i];
        prefixMarcas[i] = prefixMarcas[i - 1] + marcas[i];
    }

    int ans = INT_MIN, i = 1, j = 0;

    while ((i <= n) && (j <= n)) {
        while (j > i) {
            i++;
        }
        while ((prefixMarcas[i] - prefixMarcas[j]) < l) {
            i++;
        }
        while ((prefixMarcas[i] - prefixMarcas[j]) > h) {
            j++;
        }
        if ((prefixMarcas[i] - prefixMarcas[j] >= l) && (prefixMarcas[i] - prefixMarcas[j] <= h)) {
            ans = max(ans, prefixSums[i] - prefixSums[j]);
            if (prefixSums[i + 1] - prefixSums[i] > prefixSums[j] - prefixSums[j + 1]) i++;
            else j++;
        }
    }

    cout << ans << "\n";
}