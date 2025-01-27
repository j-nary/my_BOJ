//BOJ_1059 좋은 구간 [실버 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int L; cin >> L;
  vector<int> v(L);
  for (int i = 0; i < L; i++) cin >> v[i];
  sort(v.begin(), v.end());

  int n; cin >> n;

  int idx = upper_bound(v.begin(), v.end(), n) - v.begin();

  int left = v[idx - 1] + 1, right = v[idx] - 1;

  int res = 0;
  for (int i = left; i <= right; i++) {
    for (int j = i + 1; j <= right; j++) {
      if (i <= n && n <= j) res++;
    }
  }

  cout << res << '\n';
}