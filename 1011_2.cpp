// BOJ_1011 Fly me to the Alpha Centauri
// 수학으로 재도전

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

void test_case() {
  ll x, y; cin >> x >> y;

  double half = sqrt(y - x);
  if (ceil(half) == floor(half)) {
    cout << ceil(half) * 2 - 1 << '\n';
  } else if (round(half) == ceil(half)) {
    cout << ceil(half) * 2 - 1 << '\n';    
  } else {
    cout << floor(half) * 2 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int tc; cin >> tc;
  for (int t = 1; t <= tc; t++) {
    test_case();
  }
}