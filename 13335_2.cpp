//BOJ_13335 트럭 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, W, L;
  cin >> N >> W >> L;

  vector<int> T(N);
  for (int i = 0; i < N; i++) cin >> T[i];

  vector<int> B(W);
  int curWeight = 0, ans = 0, idx = 0;
  while(1) {
    if (idx == N) {
      int last;
      for (int i = 0; i < N; i++) {
        if (B[i] != 0) {
          last = W - i;
          break;
        }
      }
      ans += last;
      break;
    }
    ans++;
    if (B[W - 1]) curWeight -= B[W - 1];
    for (int i = W - 1; i > 0; i--) B[i] = B[i - 1];
    B[0] = 0;
    if (curWeight + T[idx] <= L) {
      B[0] = T[idx];
      curWeight += T[idx++];
    }
  }
  cout << ans << '\n';
}