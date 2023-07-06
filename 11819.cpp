//BOJ_11819 The Shortest does not Mean the Simplest [실버 1]
//gcc에는 int128이 존재
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

//A^B(mod C) 구하기
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll a, b, c;
    cin >> a >> b >> c;
    
    __int128_t A = a, B = b, C= c;
    __int128_t res = 1;
    while (B > 0) {
        if (B & 1) res = res * A % C;
        B /= 2;
        A = A * (A % C) % C;
    }

    cout << (long long)res << '\n';
}