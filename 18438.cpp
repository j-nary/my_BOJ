// BOJ_18438 LCS 5 [다이아몬드 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int dp[2][7003];
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  string str1, str2;
  cin >> str1 >> str2;
  str1 = "0" + str1; str2 = "0" + str2;
  int len1 = str1.length(), len2 = str2.length();
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      if (str1[i] == str2[j]) dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
      else dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
    }
  }

  cout << dp[len1 % 2][len2] << '\n';
}