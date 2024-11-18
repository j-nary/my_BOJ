#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  double a,b;
  cin >> a >> b;

  double cal = a - (a * b / 100);
  if (cal < 100) cout << 1 << '\n';
  else cout << 0 << '\n';
}