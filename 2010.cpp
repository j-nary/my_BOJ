#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  vector<int> v(N);
  cin >> v[0];
  for (int i = 1; i < N; i++) {
    int ip; cin >> ip;
    v[i] = ip - 1;
  }

  int ans = 0;
  for (int it: v) ans += it;
  cout << ans << '\n';
  

}