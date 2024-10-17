//BOJ_21967 세워라 반석 위에 [실버 3]
//시간초과: 구간의 최대/최소 값을 O(N)만에 찾을 방법이 없다
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  vector<int> v(N);

  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  vector<int> minV(N), maxV(N);
  minV[0] = v[0]; maxV[0] = v[0];

  for (int i = 0; i < N; i++) {
    minV[i] = min(minV[i - 1], v[i]);
    maxV[i] = max(maxV[i - 1], v[i]);
  }

  int ans = 0, s = 0, e = 0;
  while(s < N) {
    int maxVal = maxV[e - 1];
    int minVal = minV[e - 1];
    
    if (maxVal - minVal <= 2) ans = max(ans, e - s);

    if (maxVal - minVal > 2 || e == N) s++;
    else e++;

  }
  cout << ans << '\n';
}