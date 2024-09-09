// BOJ_25418 정수 a를 k로 만들기 [실버 3]
// DP로 다시 풀어보기

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int A, K;
int dp[1000006];

int solve(int num) {
  if (num <= A) return dp[A] = 0;

  if (dp[num]) return dp[num];

  if (num % 2 == 0 && num / 2 >= A) return dp[num] = min(solve(num / 2) + 1, solve(num - 1) + 1);
  if (num - 1 >= A) return dp[num] = solve(num - 1) + 1;

  return 0;
}
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> A >> K;

  cout << solve(K) << '\n';
}