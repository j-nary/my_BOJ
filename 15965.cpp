//BOJ_15965 K번째 소수 [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool sosu[100000008];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int K; cin >> K;
    sosu[1] = true;
    for (int i = 2; i * i < 100000008; i++) {
        if (sosu[i]) continue;
        for (int j = i + i; j < 100000008; j += i) {
            sosu[j] = true;
        }
    }

    int ans = 0, cnt = 0;;
    for (int i = 2; i < 100000008; i++) {
        if (!sosu[i]) cnt ++;
        if (cnt == K) {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';
}