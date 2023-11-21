//BOJ_11057 오르막 수 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
const int MOD = 10007;
int dp[1003][10];  // dp[i][j] : i길이의 j로 끝나는 오르막 수의 개수
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= 9; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans += dp[N][i];
    }

    cout << ans % MOD << '\n';
}