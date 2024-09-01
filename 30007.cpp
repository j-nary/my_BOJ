#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void test_case() {
  int A,B,X;
  cin >> A >> B >> X;

  cout << A * (X - 1) + B << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int tc; cin >> tc;
  for (int t = 1; t <= tc; t++) {
    test_case();
  }
}