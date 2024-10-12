//BOJ_2993 세 부분 [실버 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  string str;
  cin >> str;

  int len = str.length();
  string tmp, ans = str;
  for (int i = 1; i < len - 2; i++) {
    for (int j = i + 1; j < len; j++) {
      tmp = str;

			reverse(tmp.begin(), tmp.begin() + i);
			reverse(tmp.begin() + i, tmp.begin() + j);
			reverse(tmp.begin() + j, tmp.end());

      ans = min(ans, tmp);
    }
  }
  cout << ans << '\n';
}