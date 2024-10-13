//BOJ_30105 아즈버의 이빨 자국 [골드 5]
#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  vector<int> X(N), K;
  unordered_set<int> us;
  set<int> dist;

  for (int i = 0; i < N; ++i) {
    cin >> X[i];
    us.insert(X[i]);
  }

  for (int i = 1; i <= N / 2; ++i) dist.insert(X[i] - X[0]);

  for (auto d: dist) {
    bool flag = true;
    for (int i = 0; i < N; ++i) {
      if (us.find(X[i] - d) == us.end() && us.find(X[i] + d) == us.end()) {
        flag = false; break;
      }
    }
    if (flag) {
      K.push_back(d);
    }
  }
  
  cout << K.size() << '\n';
  if (K.size() == 0) return 0;
  sort(K.begin(), K.end());
  for (auto elem: K) cout << elem << ' ';
  cout << '\n';
}