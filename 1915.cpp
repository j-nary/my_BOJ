//BOJ_1915 가장 큰 정사각형 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int dp[1003][1003];
int Arr[1003][1003];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char ip; cin >> ip;
            Arr[i][j] = ip - '0';
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!Arr[i][j]) continue;
            Arr[i][j] = min({Arr[i - 1][j - 1], Arr[i - 1][j], Arr[i][j - 1]}) + 1;
            ans = max(ans, Arr[i][j]);
        }
    }

    cout << ans * ans << '\n';
}