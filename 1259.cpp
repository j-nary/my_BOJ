//BOJ_10988 팰린드롬인지 확인하기 [브론즈 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  while(1) {
    string str;
    cin >> str;

    if (str == "0") break;

    bool flag = true;
    int full = str.length();
    int half = full / 2;
    for (int i = 0; i < half; i++) {
      if (str[i] != str[full - 1 - i]) {
        flag = false;
        
        break;
      }
    }
    if (flag) cout << "yes" << '\n';
    else cout << "no" << '\n';
  }


}