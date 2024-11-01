//BOJ_18429 근손실 [실버 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, K, ans;
vector<int> v;
vector<int> path;
bool chk[10];

void backtracking(int weight) {
  if (path.size() == N) ans++;
  for (int i = 0; i < N; i++) {
    if (chk[i]) continue;

    int nw = weight + v[i] - K;
    if (nw >= 500) {
      chk[i] = true;
      path.push_back(v[i]);
      backtracking(nw);
      chk[i] = false;
      path.pop_back();
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> K;
  v.resize(N);
  for (int i = 0; i < N; i++) cin >> v[i];

  backtracking(500);
  cout << ans << '\n';
}