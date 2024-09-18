//BOJ_2502 떡 먹는 호랑이 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int D, K;
int dp[100005];
int call1, call2;

void fibo(int N) {
  if (N == 1) call1++;
  else if (N == 2) call2++;
  else {
    fibo(N - 1);
    fibo(N - 2);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> D >> K;

  fibo(D);

  for(int i = 1; call1 * i < K; i++) {
    for (int j = i; call2 * j < K; j++) {
      if (call1 * i + call2 * j == K) {
        cout << i << '\n' << j << '\n';
        return 0;
      }
    }
  }
}