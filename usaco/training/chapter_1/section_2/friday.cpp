/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: friday
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

const int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int freq[7];

bool isLeap(int x) {
    if (x % 400 == 0) return 1;
    if (x % 100 == 0) return 0;
    if (x % 4) return 0;
    return 1;
}

int main() {
    ofstream cout ("friday.out");
    ifstream cin ("friday.in");

    int n; cin >> n;
    int dia = 13 % 7;
    for (int i = 1900; i < 1900 + n; i++) {
        for (int j = 0; j < 12; j++) {
            freq[dia]++;
            dia += meses[j];
            if ((j == 1) && (isLeap(i))) dia++;
            dia %= 7;
        }
    }

    cout << freq[6] << " ";
    for (int i = 0; i < 6; i++) cout << freq[i] << " \n"[i == 5];

    return 0;
}