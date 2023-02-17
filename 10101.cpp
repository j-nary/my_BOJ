#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int a, b, c; cin >> a >> b >> c;

    if (a+b+c != 180) {
        cout << "Error" << endl;
    }
    else if (a == b && b == c) {
        cout << "Equilateral" << endl;
    }
    else if (a == b || b == c || a == c) {
        cout << "Isosceles" << endl;
    }
    else {
        cout << "Scalene" << endl;
    }
}