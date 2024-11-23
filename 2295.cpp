//BOJ_2295 세 수의 합 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) cin >> v[i];

  vector<int> twoSum;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      twoSum.push_back(v[i] + v[j]);
    }
  }

  sort(v.begin(), v.end());
  sort(twoSum.begin(), twoSum.end());

  int res = 0;

  for (int k = N - 1; k >= 0; k--) {
    for (int i = 0; i < k; i++) {
      int target = v[k] - v[i];
      if (binary_search(twoSum.begin(), twoSum.end(), target)) res = max(res, v[k]);
    }
  }

  cout << res << '\n';
}