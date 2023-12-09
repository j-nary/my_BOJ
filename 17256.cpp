#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int a1, a2, a3;
    int c1, c2, c3;
    cin >> a1 >> a2 >> a3;
    cin >> c1 >> c2 >> c3;

    cout << abs(a3 - c1) << " ";
    if (a2 > c2) {
        cout << a2 / c2 << " ";
    } else {
        cout << c2 / a2 << " ";
    }
    cout << abs(a1 - c3) << "\n";
}