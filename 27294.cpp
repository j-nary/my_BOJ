#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T, S; cin >> T >> S;
    if (T >= 12 && T <= 16) {   // 점심
        if (!S) cout << "320\n";
        else cout << "280\n";
    } else {    // 그 외
        cout << "280\n";
    }
}