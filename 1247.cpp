//BOJ_1247 부호 [브론즈 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 0; i < 3; i++) {
        int N; cin >> N;
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            long long ip; cin >> ip;
            sum += ip;
        }
        if (sum > 0) cout << '+' << '\n';
        else if (sum < 0) cout << "-\n";
        else cout << "0\n";
    }
}