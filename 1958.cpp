//BOJ_1958 LCS 3 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int dp[102][102][102];
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  string str1, str2, str3;
  cin >> str1 >> str2 >> str3;
  str1 = "0" + str1;
  str2 = "0" + str2;
  str3 = "0" + str3;

  int len1 = str1.length(), len2 = str2.length(), len3 = str3.length();
  for (int i = 1; i < len1; i++) {
    for (int j = 1; j < len2; j++) {
      for (int k = 1; k < len3; k++) {
        if (str1[i] == str2[j] && str2[j] == str3[k]) dp[i][j][k] = dp[i - 1][j - 1][k -1] + 1;
        else dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
      }
    }
  }

  cout << dp[len1 - 1][len2 - 1][len3 - 1] << '\n';
}