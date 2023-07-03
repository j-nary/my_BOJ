//BOJ_11819 The Shortest does not Mean the Simplest [실버 1]
//gcc에는 int128이 존재
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

ll A, B, C;

//A^B(mod C) 구하기
ll Pow(ll a, ll b, ll c) {
    if (b == 0) return 1;
    ll half = Pow(a, b/2, c);
    if (b % 2 == 0) return half * half % c;
    else return a * half % c * half % c;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> A >> B >> C;
    cout << Pow(A, B, C) << '\n';
}