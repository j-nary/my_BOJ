//BOJ_3020 개똥벌레 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

ll Btm[500005], Top[500005];
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, H;
  cin >> N >> H;
  for (int i = 0; i < N; i += 2) {
    int b,t; cin >> b >> t;
    Btm[b]++; Top[t]++;
  }
  for (int i = H - 2; i >= 0; i--) {
    Top[i] += Top[i + 1];
    Btm[i] += Btm[i + 1];
  }

  pair<ll, int> ans = {1e13, 0};
  for (int i = 1; i <= H; i++) {
    ll broken = Btm[i] + Top[H - i + 1];
    if (broken < ans.first) ans = {broken, 1};
    else if (broken == ans.first) ans.second++;
  }
  cout << ans.first << " " << ans.second << '\n';
}