//BOJ_2410 2의 멱수의 합 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MOD = 1000000000;
int N, len;
int dp[1000006];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  
  cin >> N;
  for (int i = 1; i <= N; i *= 2) {
    for (int j = 1; j <= N; j++) {
      if (i == j) dp[j]++;
      else if (i < j) dp[j] = (dp[j] + dp[j - i]) % MOD;
    }
  }
  cout << dp[N] % MOD << '\n';
}