#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 100100;

struct Reta {
    int a, b, f, g;
};

bool comp(const Reta &a, const Reta &b) {
    if (a.a <= b.a) return 1;
    return 0;
}

int N, X1, X2;
Reta arr[MAXN];

bool test(int i, int j) {
    if (arr[i].a == arr[j].a) return 0;
    if ((arr[i].f >= arr[j].f) && (arr[i].g <= arr[j].g)) return 1;
    return 0;
}

int32_t main() {
    cin >> N >> X1 >> X2;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].a >> arr[i].b;
        arr[i].f = X1 * arr[i].a + arr[i].b;
        arr[i].g = X2 * arr[i].a + arr[i].b;
    }

    sort(arr, arr + N, comp);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (test(i, j)) ans++;
        }
    }

    cout << ans << "\n";
}