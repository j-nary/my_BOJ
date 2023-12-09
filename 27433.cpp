#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    long long N; cin >> N;
    if (N < 2) {
        cout << 1 << '\n';
        return 0;
    }
    for (long long i = N- 1; i > 1; i--) {
        N *= i;
    }
    cout << N << '\n';
}