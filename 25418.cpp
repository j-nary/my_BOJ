//BOJ_25418 정수 a를 k로 만들기 [실버 3]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
bool chk[1000006];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, K; cin >> N >> K;

  q.push({N, 0});
  while(!q.empty()) {
    auto [cur, depth] = q.front();
    q.pop();

    if (cur == K) {
      cout << depth << '\n';
      return 0;
    }

    if (cur * 2 < 1000006 && !chk[cur * 2]) {
      chk[cur * 2] = true;
      q.push({cur * 2, depth + 1});
    }

    if (!chk[cur + 1]) {
      chk[cur + 1] = true;
      q.push({cur + 1, depth + 1});
    }
  }
  
}