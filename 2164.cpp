//BOJ_2164 카드2 [실버 4]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  queue<int> q;
  for (int i = 1; i <= N; i++) q.push(i);
  if (N == 1) { cout << q.front() << '\n'; return 0; }
  while (!q.empty()) {
    q.pop();
    int card = q.front();
    if (q.size() == 1) {
      cout << card << '\n';
      break;
    }
    q.pop();
    q.push(card);
  }  
}