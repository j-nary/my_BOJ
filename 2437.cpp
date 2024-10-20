//BOJ_2437 저울 [골드 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) cin >> v[i];
  sort(v.begin(), v.end());

  int res = 0;
  for (int i = 0; i < N; i++) {
    if (v[i] > res + 1) break;
    res += v[i];
  }
  cout << res + 1 << '\n';
}