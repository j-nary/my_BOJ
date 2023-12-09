#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    double N; cin >> N;
    cout << (int)(N * (78.0/100)) << " ";

    cout << (int)(N - ((N * 2.0/10) * (22.0/100))) << "\n";
}