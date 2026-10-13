#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100100;

int n, d;
stack<int> pilha;

int main() {
    while (true) {
        cin >> n >> d;
        if (n == 0) break;
        int apagados = 0;
        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            int a = c - '0';

            while ((apagados < d) && (!pilha.empty()) && (a > pilha.top())) {
                pilha.pop();
                apagados++;
            }

            pilha.push(a);
        }

        vector<int> ans;
        while (!pilha.empty()) {
            ans.push_back(pilha.top());
            pilha.pop();
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < n - d; i++) cout << ans[i];
        cout << "\n";
    }
}