/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: preface
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int freq[7], val[] = {1, 5, 10, 50, 100, 500, 1000};
char letter[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

void romanConv(int x) {
    for (int i = 6; i >= 0; i--) {
        if (i % 2) {
            freq[i] += x / val[i];
            x = x % val[i];
            if (x / val[i - 1] == 4) {
                freq[i]++;
                freq[i - 1]++;
                x -= 4 * val[i - 1];
            }
        } else {
            freq[i] += x / val[i];
            x = x % val[i];
            if ((x > 0) && (x / val[i - 2] == 9)) {
                freq[i]++;
                freq[i - 2]++;
                x -= 9 * val[i - 2];
            }
        }
    }
}

int main() {
    ifstream cin ("preface.in");
    ofstream cout ("preface.out");
    int n; cin >> n;
    for (int i = 1; i <= n; i++) romanConv(i);
    for (int i = 0; i < 7; i++) {
        if (!freq[i]) continue;
        cout << letter[i] << " " << freq[i] << "\n";
    }
    return 0;
}