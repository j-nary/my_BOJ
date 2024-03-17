//BOJ_15990 1, 2, 3 더하기 5
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
const int MOD = 1000000009;

long long dp[4][100005];

void test_case() {
    int N; cin >> N;

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[1][3] = 1;
    dp[2][3] = 1;
    dp[3][3] = 1;
    for (int i = 4; i <= N; i++) {
        dp[1][i] = (dp[2][i - 1] + dp[3][i - 1]) % MOD;
        dp[2][i] = (dp[1][i - 2] + dp[3][i - 2]) % MOD;
        dp[3][i] = (dp[1][i - 3] + dp[2][i - 3]) % MOD;
    }

    long long ans = 0;
    for (int i = 1; i <= 3; i++) {
        ans += dp[i][N];
    }
    cout << ans % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
        memset(dp, 0, sizeof(dp));
    }
}