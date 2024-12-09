//BOJ_10836 여왕벌 [골드 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int ZIP[702][702];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int M, N; cin >> M >> N;

  for (int i = 0; i < M; i++)
    for (int j = 0; j < M; j++) ZIP[i][j] = 1;

  while (N--) {
    int grow0, grow1, grow2;
    cin >> grow0 >> grow1 >> grow2;

    for (int i = M - 1; i >= 0; i--) {
      if (grow0 > 0) { grow0--; }
      else if (grow1 > 0) { grow1--; ZIP[i][0]++; }
      else { ZIP[i][0] += 2; }
    }

    for (int j = 1; j < M; j++) {
      if (grow0 > 0) { grow0--; }
      else if (grow1 > 0) { grow1--; ZIP[0][j]++; }
      else { ZIP[0][j] += 2; }
    }

  }

  for (int i = 1; i < M; i++) {
    for (int j = 1; j < M; j++) {
      ZIP[i][j] = max({ZIP[i - 1][j], ZIP[i][j - 1], ZIP[i - 1][j - 1]});
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      cout << ZIP[i][j] << ' ';
    }
    cout << '\n';
  }


}