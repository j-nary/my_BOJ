//BOJ_5623 수열의 합 [실버 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int S[1001][1001];
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> S[i][j];
    }
  }

  if ( N == 2) {
    cout << "1 1\n";
    return 0;
  }

  // a + b = 3
  // a + c = 6
  // a + d = 7  
  // b + c = 5
  // b + d = 6
  // c + d = 9

  // 2a + b + c = 9 = 2a + 5 = 9 -> a = 2

  int a = (S[1][2] + S[1][3] - S[2][3]) / 2;
  cout << a;
  for (int i = 2; i <= N; i++) {
    cout << ' ' << S[1][i] - a;
  }

  cout << '\n';
}