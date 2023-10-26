#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, s, u, v;
    scanf("%d%d", &p, &s);
    pair<int, int> arr[s];
    for (int i = 0; i < s; i++) {
        scanf("%d%d", &u, &v);
        arr[i].first = u;
        arr[i].second = v;
    }
    sort(arr, arr+s);
    int inicio = arr[0].first;
    int final = arr[0].second;
    for (int i = 1; i < s; i++) {
        u = arr[i].first;
        v = arr[i].second;
        if ((u <= final) && (v > final)) {
            final = v;
        } else if (u > final) {
            cout << inicio << " " << final << "\n";
            inicio = u;
            final = v;
        }
    }
    cout << inicio << " " << final << "\n";
}