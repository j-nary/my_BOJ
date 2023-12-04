//BOJ_2501 약수 구하기 [브론즈 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K; cin >> N >> K;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) cnt++;
        if (cnt == K) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
}