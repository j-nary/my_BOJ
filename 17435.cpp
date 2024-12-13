//BOJ_17435 합성함수와 쿼리 [골드 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAX = 500005;
const int MAX_D = 19; // 2^k >= MAX

int nxt[MAX][MAX_D];
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int M; cin >> M;
  for (int i = 1; i <= M; i++) cin >> nxt[i][0];

  for (int j = 1; j < MAX_D; j++)
    for (int i = 1; i <= M; i++)
      nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
  
  int Q; cin >> Q;
  while (Q--) {
    int N, X; cin >> N >> X;
    for (int j = MAX_D - 1; j >= 0; j--) {
      if (N >= 1 << j) {
        N -= 1 << j;
        X = nxt[X][j];
      }
    }
    cout << X << '\n';
  }
}