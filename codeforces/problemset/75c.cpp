#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int div = gcd(a, b);
    vector<int> divs;
    for (int i = 1; i * i <= div; i++) {
        if (div % i == 0) {
            divs.push_back(i);
            if (i * i != div) divs.push_back(div / i);
        }
    }
    sort(divs.begin(), divs.end());
    int qq; cin >> qq;
    while (qq--) {
        int low, high; cin >> low >> high;
        int idx = upper_bound(divs.begin(), divs.end(), high) - divs.begin();
        if (divs[idx - 1] >= low) cout << divs[idx - 1] << "\n";
        else cout << "-1\n";
    }
}