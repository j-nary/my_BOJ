//BOJ_29716 풀만한문제 [브론즈 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int J, N;
  cin >> J >> N;
  cin.ignore();

  int ans = 0;
  for (int i = 0; i < N; i++) {
    string str;
    getline(cin, str);

    int cnt = 0;
    for (int j = 0; j < str.size(); j++) {
      if (str[j] >= 'A' && str[j] <= 'Z') cnt += 4;
      else if (str[j] == ' ') cnt ++;
      else cnt += 2;
    }

    ans += (cnt <= J);
  }
  cout << ans << '\n';
}