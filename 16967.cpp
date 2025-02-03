//BOJ_16967 배열 복원하기 [실버 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int A[302][302];
int B[602][602];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int H, W, X, Y;
  cin >> H >> W >> X >> Y;

  for (int i = 1; i <= H + X; i++)
    for (int j = 1; j <= W + Y; j++) cin >> B[i][j];

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (i - X > 0 && j - Y > 0) A[i][j] = B[i][j] - A[i - X][j - Y];
      else A[i][j] = B[i][j];
      cout << A[i][j] << " ";
    }
    cout << '\n';
  }
}