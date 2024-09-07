#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;
  int ans = 0;
  ans += min({a, b, c});

  cin >> a >> b;
  ans += min(a, b);

  cout << ans - 50 << '\n';
}