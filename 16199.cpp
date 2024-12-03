#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int y, m, d;
  cin >> y >> m >> d;

  int sy, sm, sd;
  cin >> sy >> sm >> sd;

  int man = sy - y;
  if (sm < m || (sm == m && sd < d)) man--;

  cout << man << '\n';
  cout << sy - y + 1 << '\n';
  cout << sy - y << '\n';
}