//BOJ_14954 Happy Number [브론즈 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  string str;
  cin >> str;

  int calc;
  vector<int> chk;

  while(1) {
    calc = 0;
    for (int i = 0; i < str.size(); i++) {
      calc += pow(str[i] - '0', 2);
    }
    if (calc == 1) {
      cout << "HAPPY" << '\n';
      break;
    }
    if (find(chk.begin(), chk.end(), calc) != chk.end()) {
      cout << "UNHAPPY" << '\n';
      break;
    }
    chk.push_back(calc);
    str = to_string(calc);
  }
}
