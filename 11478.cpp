//BOJ_11478 서로 다른 부분 문자열의 개수 [실버 3]
#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  string S; cin >> S;
  set<string> ans;
  for (int i = 0; i < S.size(); i++) {
    for (int j = i; j < S.size(); j++) {
      ans.insert(S.substr(i, j - i + 1));
    }
  }
  cout << ans.size() << '\n';
}