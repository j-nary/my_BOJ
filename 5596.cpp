#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int a = 0, b = 0, ip;
    for (int i = 0; i < 4; i++) {
        cin >> ip;
        a += ip;
    }
    for (int i = 0; i < 4; i++) {
        cin >> ip;
        b += ip;
    }
    cout << ((a > b) ? a : b) << '\n';
}