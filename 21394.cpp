//BOJ_21394 숫자 카드 [브론즈 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void test_case() {
  int Card[10];
  int len = 0;
  for (int i = 1; i < 10; i++) {
    cin >> Card[i];
    len += Card[i];
  }

  Card[9] += Card[6];
  Card[6] = 0;

  int Ans[1003];
  int idx = 9;
  for (int i = 0; i < len / 2; i++) {
    while (!Card[idx]) idx--;
    Ans[i] = idx;
    --Card[idx];
    while (!Card[idx]) idx--;
    Ans[len - 1 - i] = idx;
    --Card[idx];
  }

  if (len % 2) {
    while(!Card[idx]) idx--;
    Ans[len / 2] = idx;
  }

  for (int i = 0; i < len; i++) {
    cout << Ans[i] << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int tc; cin >> tc;
  for (int t = 1; t <= tc; t++) {
    test_case();
  }
}