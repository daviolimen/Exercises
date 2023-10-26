#include <iostream>
using namespace std;

int main() {
    int a, b, c, h, l;
    cin >> a >> b >> c >> h >> l;
    if (((a <= h) && ((b <= l) || (c <= l))) || ((b <= h) && ((a <= l) || (c <= l))) || ((c <= h) && ((a <= l) || (b <= l)))) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }
}