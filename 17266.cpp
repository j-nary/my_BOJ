//BOJ_17266 어두운 굴다리 [실버 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> loc;
int N, M;

bool isBright(int height) {
  if (loc[0] - height > 0) return false;

  int cur = loc[0] + height;
  for (int i = 1; i < M; i++) {
    if (cur < loc[i] - height) return false;
    cur = loc[i] + height;
  }
  if (cur < N) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int ip; cin >> ip;
    loc.push_back(ip);
  }

  int left = 0, right = N;
  int ans = 1e9;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (isBright(mid)) {
      ans = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  cout << ans << '\n';
}