//BOJ_2851 슈퍼 마리오 [브론즈 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  vector<int> mush(10);
  for (int i = 0; i < 10; i++) cin >> mush[i];

  for (int i = 1; i < 10; i++) mush[i] += mush[i - 1];

  int lower = mush[lower_bound(mush.begin(), mush.end(), 100) - mush.begin() - 1];
  int upper = mush[lower_bound(mush.begin(), mush.end(), 100) - mush.begin()];
  
  if (abs(lower - 100) < abs(upper - 100)) cout << lower << '\n';
  else cout << upper << '\n';
}