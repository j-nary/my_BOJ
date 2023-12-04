#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    string s = to_string(A) + to_string(B);
    A = stoll(s);
    s = to_string(C) + to_string(D);
    C = stoll(s);
    cout << A + C << '\n';
}