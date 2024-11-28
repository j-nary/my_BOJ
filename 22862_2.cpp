//BOJ_22862 가장 긴 짝수 연속한 부분 수열 (large)
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, K, ans;
vector<int> v;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> K;
  v.resize(N);
  for (int i = 0; i < N; i++) cin >> v[i];

  int s = 0, e = 0, except = 0, ans= 0;
  while (s < N && e < N) {
    if (v[e] % 2 == 1) {
      if (except < K) {
        except++;
      } else {
        while (v[s] % 2 == 0) s++;
        s++;
      }
    }
    ans = max(ans, e - s + 1 - except);
    e++;
  }
  cout << ans << '\n';
}