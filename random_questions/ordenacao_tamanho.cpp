#include <bits/stdc++.h>
using namespace std;

string arr[51];

bool cmp(string a, string b) {
    return (a.length() > b.length());
}

void split(string linha) {
    int size = linha.length();
    int i = 0, x = 0, j = 0;
    string s;
    while (i <= size) {
        if (linha[i] == ' ' || linha[i] == '\0') {
            s = linha.substr(j, i - j);
            arr[x] = s;
            j = i + 1;
            x++;
        }
        i++;
    }
    stable_sort(arr, arr+x, cmp);

    for (int i = 0; i < x; ++i) {
        cout << arr[i];
        if (i != (x - 1)) {
            cout << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n; cin.ignore();
    string line;
    for (int ctr = 0; ctr < n; ctr++) {
        getline(cin, line);
        split(line);
    }
    return 0;
}