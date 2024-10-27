#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  string str; cin >> str;
  char mo[5] = {'a', 'e', 'i', 'o','u'};

  int cnt = 0;
  for (int i = 0; i < str.size(); i++) {
    for (int j = 0; j < 5; j++) {
      if (mo[j] == str[i]) cnt++;
    }
  }
  cout << cnt << '\n';
}