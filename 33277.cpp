//BOJ_33277 국방시계 [브론즈 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  // 24*60 = 1440분
  int N, M; cin >> N >> M;
  int totalMinutes = floor(1440.0 * M / N);

  int hours = totalMinutes / 60;
  int minute = totalMinutes % 60;
  cout << hours << ":" << ((minute < 10) ? "0" : "") << minute << '\n';  
}