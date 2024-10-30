//BOJ_29615 알파빌과 베타빌 [실버 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool F[1003];
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, M;
  cin >> N >> M;
  vector<int> line(N);
  for (int i = 0; i < N; i++) cin >> line[i];
  for (int i = 0; i < M; i++) {
    int ip; cin >> ip;
    F[ip] = true;
  }

  int ans = 0;
  for (int i = 0; i < M; i++) {
    if (F[line[i]]) continue;
    ans++;
    for (int j = N - 1; j > i; j--) {
      if (F[line[j]]) swap(line[i], line[j]);
    }
  }
  cout << ans << '\n';
}