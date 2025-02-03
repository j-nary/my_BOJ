//BOJ_4347 Tic Tac Toe [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool test_case() {
  char G[3][3];
  int XCnt = 0, OCnt = 0;
  bool isBlank = false;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      cin >> G[i][j];
      if (G[i][j] == 'X') XCnt++;
      else if (G[i][j] == 'O') OCnt++;
      else isBlank = true;
    }
  
  if (XCnt < OCnt || XCnt > OCnt + 1) return false;

  bool isXWin = false, isOWin = false;
  // horizontal
  for (int i = 0; i < 3; i++) {
    if (G[i][0] != '.' && G[i][0] == G[i][1] && G[i][1] == G[i][2]) {
        if (G[i][0] == 'X') isXWin = true;
        else isOWin = true;
    }
  }

  // vertical
  for (int j = 0; j < 3; j++) {
    if (G[0][j] != '.' && G[0][j] == G[1][j] && G[1][j] == G[2][j]) {
        if (G[0][j] == 'X') isXWin = true;
        else isOWin = true;
    }
  }

  // diagonal
  if (G[1][1] != '.') {
    if (G[0][0] == G[1][1] && G[1][1] == G[2][2]) {
      if (G[1][1] == 'X') isXWin = true;
      else isOWin = true;
    }
    if (G[0][2] == G[1][1] && G[1][1] == G[2][0]) {
      if (G[1][1] == 'X') isXWin = true;
      else isOWin = true;
    }
  }

  if (isXWin && isOWin) return false;
  if (!isBlank && !isXWin && !isOWin) return true;
  if (isXWin && (XCnt != OCnt + 1)) return false;
  if (isOWin && (XCnt != OCnt)) return false;

  return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int tc; cin >> tc;
  for (int t = 1; t <= tc; t++) {
    if (test_case()) cout << "yes\n";
    else cout << "no\n";
  }
}