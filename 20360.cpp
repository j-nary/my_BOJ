//BOJ_20360 Binary numbers [브론즈 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;

    int tmp = 0;
    while(N != 0) {
        if (N & 1 == 1) {
            cout << tmp << ' ';
        }
        tmp++;
        N = N >> 1;
    }
    cout << '\n';
}