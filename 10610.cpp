//BOJ_10610 30 [실버 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  string str; cin >> str;

  bool flag = true;
  int sum = 0;
  vector<int> v;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '0') flag = false;
    sum += (str[i] - '0');
    v.push_back(str[i] - '0');
  }

  if (sum % 3 != 0 || flag) {
    cout << -1 << '\n';
    return 0;
  }

  sort(v.begin(), v.end(), greater<>());

  for (int i = 0; i < v.size(); i++) {
    cout << v[i];
  }
  cout << '\n';
}