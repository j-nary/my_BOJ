// BOJ_13711 LCS 4 [플래티넘 5]
// LCS로 접근 -> O(N^2) 시간초과
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int dp[2][100005];
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  string str1 = "0", str2 = "0";
  for (int i = 0; i < N; i++) {
    char c; cin >> c;
    str1.push_back(c);
  }
  for (int i = 0; i < N; i++) {
    char c; cin >> c;
    str2.push_back(c);
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (str1[i] == str2[j]) dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
      else dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
    }
  }

  cout << dp[N % 2][N] << '\n';
}