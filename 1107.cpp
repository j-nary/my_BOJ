//BOJ_1107 리모컨 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool broken[15];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  int M; cin >> M;
  for (int i = 0; i < M; i++) { int ip; cin >> ip; broken[ip] = true; }

  int ans = abs(N - 100);

  for (int i = 0; i < 1000006; i++) {
    string tmp = to_string(i);
    bool brokenFlag = false;
    for (int i = 0; i < tmp.size(); i++) {
      if (broken[tmp[i] - '0']) {brokenFlag = true; break;}
    }
    if (!brokenFlag) ans = min(ans, (int)(abs(N - i) + to_string(i).length()));
  }

  cout << ans << '\n';
}