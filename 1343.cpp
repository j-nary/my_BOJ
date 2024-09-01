//BOJ_1343 폴리오미노 [실버 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> v;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  string str;
  cin >> str;

  int cnt = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'X') cnt++;
    if (str[i] == '.') {
      if (cnt) {
        if (cnt % 2 == 1) {
          cout << -1 << '\n';
          return 0;
        }
        v.push_back(cnt);
        cnt = 0;
      }
      v.push_back(0);
    }
  }

  if (cnt > 0) {
    if (cnt % 2 == 1) {
      cout << -1 << '\n';
      return 0;
    }
    v.push_back(cnt);
    cnt = 0;
  }

  for (int i = 0; i < v.size(); i++) {
    if (v[i] == 0) {
      cout << '.';
      continue;
    }
    int ASize = v[i] / 4;
    for (int j = 0; j < ASize; j++) {
      cout << "AAAA";
    }
    int BSize = v[i] % 4 / 2;
    for (int j = 0; j < BSize; j++) {
      cout << "BB";
    }
  }

  cout << '\n';
}