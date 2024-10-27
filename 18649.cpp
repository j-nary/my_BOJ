//BOJ_18649 Lowest Unique [실버 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, K, M;
  cin >> N >> K >> M;
  while (M--) {
    int num;
    for (int i = 1; i <= K; i++) cout << i << " ";
    cout << endl;
    for (int i = 0; i < N- K; i++) cin >> num;
  }
}