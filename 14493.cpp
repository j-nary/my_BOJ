//BOJ_14493 과일노리 [실버 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N;
  cin >> N;

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;

    int cycle = a + b;
    int time = ans % cycle;
    ans++;
    if (time < b) ans += (b - time);
  }
  cout << ans << '\n';
}