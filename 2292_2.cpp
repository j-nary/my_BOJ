//BOJ_2292_2 벌집 [브론즈 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    // 1 -> 7 -> 19 -> 37 -> 61
    // 1
    // 1 + 6
    // 1 + 6 + 12
    // 1 + 6 + 12 + 18
    int N; cin >> N;
    int cnt = 1;
    for (int i = 0; ; i++) {
        cnt += (6 * i);
        if (cnt >= N) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
}