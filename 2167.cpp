//BOJ_2167 2차원 배열의 합 [실버 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int G[302][302];
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, M; cin >> N >> M;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) cin >> G[i][j];

  for (int i = 1; i <= N; i++)
    for (int j = 2; j <= M; j++) G[i][j] += G[i][j - 1];
  
  for (int j = 1; j <= M; j++)
    for (int i = 2; i <= N; i++) G[i][j] += G[i - 1][j];

  int K; cin >> K;
  while (K--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << G[r2][c2] - G[r1 - 1][c2] - G[r2][c1 - 1] + G[r1 - 1][c1 - 1] << '\n';
  }
}