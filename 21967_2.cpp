//BOJ_21967 세워라 반석 위에 [실버 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int cnt[10], ans;

void update(int idx) {
  ans = max(ans, cnt[idx]);
  cnt[idx] = 0;
}
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  while (N--) {
    int ip; cin >> ip;

    for (int i = 0; i <= 2; i++)
      if (ip - i > 0) cnt[ip - i]++;

    for (int i = 1; i < ip - 2; i++) update(i);

    for (int i = ip + 1; i < 10; i++) update(i);
  }

  for (int i = 1; i < 10; i++) ans = max(ans, cnt[i]);
  cout << ans << '\n';
}