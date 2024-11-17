//BOJ_13335 트럭 [실버 1]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, W, L;
  cin >> N >> W >> L;

  vector<int> T(N);
  for (int i = 0; i < N; i++) cin >> T[i];

  queue<int> q;
  int ans = 0, curWeight = 0, intersect = 0;
  for(int i = 0; i < N; i++) {
    vector<int> tmp;
    while (curWeight + T[i] > L) {
      int truck = q.front();
      tmp.push_back(truck);
      q.pop();
      curWeight -= truck;
    }
    if (!tmp.empty()) {
      ans += (W + tmp.size());
      intersect++;
    }
    q.push(T[i]);
    curWeight += T[i];
  }
  if (!q.empty()) {
    ans += (W + q.size());
  }
  cout << ans - intersect << '\n';
}