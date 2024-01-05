#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int sum = 0;
    for (int i = 0; i < 5; i++) {
        int ip; cin >> ip;
        sum += ip;
    }
    cout << sum << '\n';
}