//BOJ_1016 제곱 ㄴㄴ 수 [골드 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool sosu[1000051000006];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    sosu[1] = true;
    for (int i = 2; i <= M; i++) {
        if (sosu[i]) continue;
        for (int j = i + i; j <= M; j += i) {
            sosu[j] = true;
        }
    }

    int ans = 0;
    for (int i = N; i <= M; i++) {
        if (!sosu[i]) ans++;
    }
    cout << ans << '\n';
}