//BOJ_14697 방 배정하기 [브론즈 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  vector<int> room(3);
  for (int i = 0; i < 3; i++) cin >> room[i];

  int N; cin >> N;

  for (int i = 0; i <= N / room[0]; i++) {
    for (int j = 0; j <= N / room[1]; j++) {
      for (int k = 0; k <= N / room[2]; k++) {
        if (room[0] * i + room[1] * j + room[2] * k == N) {
          cout << 1 << '\n';
          return 0;
        }
      }
    }
  }
  
  cout << 0 << '\n';
}