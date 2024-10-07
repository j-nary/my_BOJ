//BOJ_11948 과목선택 [브론즈 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  vector<int> v;
  for (int i = 0; i < 4; i++) {
    int ip; cin >> ip;
    v.push_back(ip);
  }
  sort(v.begin(), v.end());

  int ans = 0;
  int idx = v.size() - 1;
  for (int i = 0; i < 3; i++) {
    ans += v[idx - i];
  }

  vector<int> v2;
  for (int i = 0; i < 2; i++) {
    int ip; cin >> ip;
    v2.push_back(ip);
  }

  sort(v2.begin(), v2.end());
  cout << ans + v2[v2.size() - 1] << '\n';
}