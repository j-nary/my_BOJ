//BOJ_2877 4와 7 [골드 5]
#include <bits/stdc++.h>
#include <iostream>
#include <bitset>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int K; cin >> K;
  
  // 자릿수 세기
  int digit = 1, cur = 1;
  while(1) {
    if (K < cur) {
      cur -= pow(2, digit);
      --digit;
      break;
    }
    if (K == cur) break;
    cur += pow(2, digit++);
  }

  bitset<30> B(0);
  for (int i = 0; i < K - cur; i++)
    B = bitset<30>(B.to_ulong() + 1);

  for (int i = digit - 1; i >= 0; i--) {
    if (B[i]) cout << '7';
    else cout << '4';
  }
  cout << '\n';
}