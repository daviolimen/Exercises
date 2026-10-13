#include <bits/stdc++.h>
using namespace std;

string s;
int freq[26];

void solve(char impar) {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < freq[i] / 2; j++) {
            cout << (char) (i + 'A');
        }
    }
    if (impar != '*') cout << impar;
    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < freq[i] / 2; j++) {
            cout << (char) (i + 'A');
        }
    }
}

int main() {
    cin >> s;
    for (auto c : s) {
        freq[c - 'A']++;
    }
    int ctr = 0;
    char impar = '*';
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            ctr++;
            impar = i + 'A';
        }
    }
    if (ctr > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    solve(impar);
    cout << "\n";
}