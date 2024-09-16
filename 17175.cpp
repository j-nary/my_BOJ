//BOJ_17175 피보나치는 지겨웡~ [실버 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

ll dp[51];
const ll MOD = 1000000007;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; 
  cin >> N;

  dp[0] = 1;
  dp[1] = 1;

  for (int i = 2; i <= 50; i++) {
    dp[i] = dp[i - 2] + dp[i - 1] + 1;
  }

  cout << dp[N] % MOD << '\n';
}