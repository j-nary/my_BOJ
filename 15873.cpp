#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  string str;
  cin >> str;
  if (str.length() == 3) {
    if (str[1] == '0') {
      cout << 10 + str[2] - '0' << '\n';
      return 0;
    }
    if (str[2] == '0') {
      cout << str[0] - '0' + 10 << '\n';
      return 0;
    }
  }
  if (str.length() == 4) {
    cout << 20 << '\n';
    return 0;
  }
  cout << str[0] - '0' + str[1] - '0' << '\n';
}