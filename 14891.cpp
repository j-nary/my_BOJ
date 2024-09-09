//BOJ_14891 톱니바퀴 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int wheel[4][8];

void rotate(int num, int dir, int prev) {
  bool rightFlag = false, leftFlag = false;
  if (prev != 1 && num < 3 && wheel[num][2] != wheel[num + 1][6]) {
    rightFlag = true;
  }
  if (prev != -1 && num > 0 && wheel[num][6] != wheel[num - 1][2]) {
    leftFlag = true;
  }

  int tmp = 0;
  if (dir == 1) {
    // 시계방향
    tmp = wheel[num][7];
    for (int i = 7; i > 0; i--) {
      wheel[num][i] = wheel[num][i - 1];
    }
    wheel[num][0] = tmp;
  } else {
    // 반시계방향
    tmp = wheel[num][0];
    for (int i = 0; i < 7; i++) {
      wheel[num][i] = wheel[num][i + 1];
    }
    wheel[num][7] = tmp;
  }

  if (rightFlag) {
    if (dir < 0) rotate(num + 1, 1, -1);
    else rotate(num + 1, -1, -1);
  }

  if (leftFlag) {
    if (dir < 0) rotate(num - 1, 1, 1);
    else rotate(num -1, -1, 1);
  }
}
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 8; j++) {
      char c; cin >> c;
      wheel[i][j] = c -'0';
    }
  }

  int K; cin >> K;
  for (int i = 0; i < K; i++) {
    int num, dir;
    cin >> num >> dir;

    rotate(num - 1, dir, 0);
  }

  int ans = 0;
  for (int i = 0; i < 4; i++) {
    if (wheel[i][0]) {
      ans += pow(2, i);
    }
  }

  cout << ans << '\n';
}