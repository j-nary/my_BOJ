// BOJ_14215 세 막대 [브론즈 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> v(3);
  for (int i = 0; i < 3; i++)
  {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int ans = 0;
  ans += v[0];
  ans += v[1];
  ans += min(v[2], v[0] + v[1] - 1);
  cout << ans << '\n';
}