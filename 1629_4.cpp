//BOJ_1629 곱셈 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long A, B, C;

long long Pow(long long a, long long b, long long c) {
    if (b == 0) return 1;
    long long half = Pow(a, b/2, c);
    if (b % 2 == 0) return half * half % c;
    else return a * half % c * half % c;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> A >> B >> C;
    cout << Pow(A, B, C) << '\n';
}