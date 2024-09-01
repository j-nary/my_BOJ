//BOJ_16173 점프왕 쩰리 (Small)
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int N;
bool chk[5][5];
int Map[5][5];

bool bfs() {
  queue<pair<int, int>> q;
  q.push({1, 1});
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    if (Map[r][c] == -1) return true;

    int weight = Map[r][c];

    if (r + weight <= N && Map[r + weight][c] && !chk[r + weight][c]) {
      q.push({r + weight, c});
      chk[r + weight][c] = true;
    }

    if (c + weight <= N && Map[r][c + weight] && !chk[r][c + weight]) {
      q.push({r, c + weight});
      chk[r][c + weight] = true;
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> Map[i][j];
    }
  }

  if (bfs()) {
    cout << "HaruHaru\n";
  } else {
    cout << "Hing\n";
  }
}