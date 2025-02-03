//BOJ_2138 전구와 스위치 [골드 4]
//시간 초과
#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

char flap (char c) {
  return c == '1' ? '0' : '1';
}
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  string light; cin >> light;
  string answer; cin >> answer;

  set<string> s;
  queue<pair<string, int>> q;
  q.push({light, 0});
  s.insert(light);

  while (!q.empty()) {
    auto [cur, depth] = q.front(); q.pop();

    for (int i = 0; i < N; i++) {
      string tmp = cur;
      if (i - 1 >= 0) tmp[i - 1] = flap(tmp[i - 1]);
      tmp[i] = flap(tmp[i]);
      if (i + 1 < N) tmp[i + 1] = flap(tmp[i + 1]);

      if (tmp == answer) {
        cout << depth + 1 << '\n';
        return 0;
      }

      if (s.count(tmp)) continue;
      s.insert(tmp);
      q.push({tmp, depth + 1});
    }
  }

  cout << -1 << '\n';
}