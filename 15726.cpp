#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  double A, B, C;
  cin >> A >> B >> C;
  cout << max (int(A*B/C), int(A/B*C)) << '\n';
}