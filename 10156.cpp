#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int K, N, M;
    cin >> K >> N >> M;
    int tmp = K * N - M;
    if (tmp  < 0) cout << 0 << '\n';
    else cout << tmp << '\n';
}