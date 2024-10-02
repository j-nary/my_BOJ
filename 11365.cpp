#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  string str;
  while(1) {
    getline(cin, str);
    if (str == "END") break;

    for (int i = str.size() - 1; i >= 0; i--) {
      cout << str[i];
    }
    cout << '\n';
  }
}