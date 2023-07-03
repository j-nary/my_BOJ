//BOJ_17466 N! mod P (1) [브론즈 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, P; cin >> N >> P;
    int r = 1;
    for (; N > 0; N--) {
        r = r * N % P;
    }
    cout << r << '\n';
}