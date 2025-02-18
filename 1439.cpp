#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  string S; cin >> S;
  int zeroGroup = 0, oneGroup = 0;
  char tmp = S[0];
  for (int i = 1; i < S.length(); i++) {
    if (tmp == S[i]) continue;

    if (tmp == '0') zeroGroup++;
    else oneGroup++;

    tmp = S[i];
  }

  if (tmp == '0') zeroGroup++;
  else oneGroup++;

  cout << min(zeroGroup, oneGroup) << '\n';
}