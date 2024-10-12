//BOJ_30105 아즈버의 이빨 자국 [골드 5]
//시간초과
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool chk[4003];
//4000까지가 아니라 10^9까지였다.
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  vector<int> X,K;
  int minDist = 0, maxValue = 0, cur;
  for (int i = 0; i < N; ++i) {
    cin >> cur; chk[cur] = true;
    X.push_back(cur);
    if (i > 0) {
      minDist = max(minDist, cur - X[i - 1]);
      maxValue = max(maxValue, cur);
    }
  }
  bool flag = true;
  for (int i = minDist; i <= maxValue; ++i) {
    flag = true;
    for (int j = 0; j < N; j++) {
      if (X[j] + i <= maxValue && !chk[X[j] + i] && X[j] - i >= 0 && !chk[X[j] - i]) {
        flag = false;
        break;
      }
    }
    if (flag) K.push_back(i);
  }
  cout << K.size() << '\n';
  if (K.size() == 0) return 0;
  sort(K.begin(), K.end());
  for (auto elem: K) cout << elem << ' ';
  cout << '\n';
}