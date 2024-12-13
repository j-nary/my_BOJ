//BOJ_3117 Youtube [골드 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAX = 100005;
const int MAX_D = 30; // 2^k >= 1000000009

int nxt[MAX][MAX_D];
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, K, M;
  cin >> N >> K >> M;
  M--;
  vector<int> student(N);
  for (int i = 0; i < N; i++) cin >> student[i];

  for (int i = 1; i <= K; i++) cin >> nxt[i][0];

  for (int j = 1; j < MAX_D; j++)
    for (int i = 1; i <= K; i++)
      nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
  
  for (auto start: student) {
    int X = start, cnt = M;
    for (int j = MAX_D - 1; j >= 0; j--) {
      if (cnt >= 1 << j) {
        cnt -= 1 << j;
        X = nxt[X][j];
      }
    }
    cout << X << ' ';
  }
  cout << '\n';
}
