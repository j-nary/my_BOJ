//BOJ_2609 최대공약수와 최소공배수 [브론즈 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int A, B; cin >> A >> B;
    cout << gcd(A, B) << '\n' << lcm(A, B) << '\n';
}