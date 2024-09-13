//BOJ_1051 숫자 정사각형 [실버 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, M;
char Rect[51][51];

bool isValid(int len) {
  for (int i = 1; i <= N - len + 1; i++) {
    for (int j = 1; j <= M - len + 1; j++) {
      if (Rect[i][j] == Rect[i][j + len - 1] && Rect[i][j] == Rect[i + len - 1][j] && Rect[i][j] == Rect[i + len - 1][j + len - 1]) {
        return true;
      }
    }
  }

  return false;
}
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> Rect[i][j];
    }
  }

  int ans = min(N, M);

  while(ans) {
    if (isValid(ans)) break;
    --ans;
  }

  cout << ans * ans << '\n';
}