#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    vector<int> divs;
    for (int i = 1; i <= n; i++) {
        if ((n % i) == 0) {
            divs.push_back(i);
            sum += i;
        }
    }
    int s = divs.size();
    cout << s << " divisor(es): ";
    for (int i = 0; i < s; i++) {
        cout << divs[i] << " ";
    }
    cout << "\n";
    cout << "Soma de divisores = " << sum << "\n";
    if (s == 2) {
        cout << "Primo\n";
    } else {
        cout << "Nao primo\n";
    }
}