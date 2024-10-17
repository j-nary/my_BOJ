//BOJ_25192 인사성 밝은 곰곰이 [실버 4]
#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  unordered_set<string> s;

  int ans = 0;
  for (int i = 0; i < N; i++) {
    string str; cin >> str;

    if (str == "ENTER") {
      s.clear(); continue;
    }

    if (s.find(str) == s.end()) {
      ans++;
      s.insert(str);
    }
  }
  cout << ans << '\n';
}