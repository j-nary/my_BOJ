//BOJ_10250 ACM 호텔 [브론즈 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void test_case() {
  int H, W, N;
  cin >> H >> W >> N;

  int room = N / H;
  int floor = N % H;  // 4
  if (floor) room++;

  string roomStr = (room / 10 == 0 ? "0" : "") + to_string(room);
  cout << (floor ? floor : H) << roomStr << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int tc; cin >> tc;
  for (int t = 1; t <= tc; t++) {
    test_case();
  }
}