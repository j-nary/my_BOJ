//BOJ_5554 심부름 가는 길 [브론즈 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int sum = 0;
  for (int i = 0; i < 4; i++) {
    int ip; cin >> ip;
    sum += ip;
  }

  cout << sum / 60 << '\n' << sum % 60 << '\n';
}