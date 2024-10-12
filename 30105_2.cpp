//BOJ_30105 아즈버의 이빨 자국 [골드 5]
#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int, bool> um;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  vector<int> X(N), K;
  unordered_set<int> us;
  int minDist = 0, cur;
  for (int i = 0; i < N; ++i) {
    cin >> X[i];
    um.insert({X[i], true});
    if (i > 0) minDist = max(minDist, X[i] - X[i - 1]);
  }
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      us.insert(X[j] - X[i]);
    }
  }
  bool flag = true;
  for (auto dist: us) {
    flag = true;
    for (int j = 0; j < N; j++) {
      if (um.find(X[j] + dist) == um.end() && um.find(X[j] - dist) == um.end()) {
        flag = false;
        break;
      }
    }
    if (flag) K.push_back(dist);
  }
  cout << K.size() << '\n';
  if (K.size() == 0) return 0;
  sort(K.begin(), K.end());
  for (auto elem: K) cout << elem << ' ';
  cout << '\n';
}