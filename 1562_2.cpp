//BOJ_1562 계단 수 [골드 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

int N;
const int MOD = 1000000000;
ll dp[101][10][1 << 10];    //pos, used, last

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    if (N < 10) {
        cout << 0 << '\n';
        return 0;
    }
    if (N == 10) {
        cout << 1 << '\n';
        return 0;
    }
    int full = (1 << 10) - 1;
    for (int i = 1; i <= 9; i++) {
        dp[1][i][1 << i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= full; k++) {
                if (j - 1 >= 0) dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % MOD;
                if (j + 1 < 10) dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 10; i++) {
        ans = (ans + dp[N][i][full]) % MOD;
    }
    cout << ans % MOD << '\n';
}