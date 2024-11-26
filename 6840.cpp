#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  vector<int> v(3);
  for (int i = 0; i < 3; i++) cin >> v[i];

  sort(v.begin(), v.end());
  cout << v[1] << '\n';
}