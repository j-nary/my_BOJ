//BOJ_1105 팔 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = unsigned long long;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  string L, R;
  cin >> L >> R;

  if (L.size() != R.size()) { cout << "0\n"; return 0; }

  int ans = 0;
  int len = L.size();
  for (int i = 0; i < len; i++) {
    if (L[i] == R[i] && L[i] == '8') ans++;
    else if (L[i] != R[i]) break;
  }
  cout << ans << '\n';
}