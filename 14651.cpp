//BOJ_14651 걷다보니 신천역 삼 (Large)
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
const int MOD = 1e9 + 9;
int N;
int dp[3][33334];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  if (N <= 1) {
    cout << "0\n";
    return 0;
  }

  dp[0][2] = 2;
  dp[1][2] = 2;
  dp[2][2] = 2;

  for (int i = 3; i <= N; i++) {
    dp[0][i] += ((dp[0][i - 1] + dp[1][i - 1]) % MOD + dp[2][i - 1]) % MOD;
    dp[1][i] += ((dp[0][i - 1] + dp[1][i - 1]) % MOD + dp[2][i - 1]) % MOD;
    dp[2][i] += ((dp[0][i - 1] + dp[1][i - 1]) % MOD + dp[2][i - 1]) % MOD;
  }

  cout << dp[0][N] << '\n';
}