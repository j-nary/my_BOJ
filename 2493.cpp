//BOJ_2493 탑 [골드 5]
#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

int top[500005];
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


  int N, height; cin >> N;
  stack<pair<int, int>> s;
  for (int i = 0; i < N; i++) {
    cin >> height;
    while (!s.empty()) {
      if (s.top().second > height) {
        cout << s.top().first << '\n';
        break;
      } else s.pop();
    }

    if (s.empty()) cout << 0 << '\n';
    s.push({i + 1, height});
  }
}
// 4
// 7
// 5
// 9
// 6