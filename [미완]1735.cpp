#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int a1, a2; cin >> a1 >> a2;
    int b1, b2; cin >> b1 >> b2;

    int c1, c2;
    c2 = a2 * b2;
    c1 = a1*b2 + b1*a2;

    //기약분수 만들기
    for (int i = max(c1, c2); i > 1; i--) {
        if (c1 % i == 0 && c2 % i == 0) {
            c1 /= i;
            c2 /= i;
            break;
        }
    }

    cout << c1 << " " << c2 << '\n';
}