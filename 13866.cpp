#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  vector<int> v(4);
  for (int i = 0; i < 4; i++) cin >> v[i];
  sort(v.begin(), v.end());

  cout << abs((v[0] + v[3]) - (v[1] + v[2])) << '\n';
}