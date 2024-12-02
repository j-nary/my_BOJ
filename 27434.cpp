#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  if (!N) { cout << 1 << '\n'; return 0; }
  unsigned long long int ans = 1;
  for (int i = N; i > 0; i--) ans *= i;
  cout << ans << '\n';
}