//BOJ_2212 센서 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, K;
  cin >> N >> K;
  vector<int> sensor(N);
  for (int i = 0; i < N; i++) cin >> sensor[i];
  sort(sensor.begin(), sensor.end());

  vector<int> dist(N-1);
  for (int i = 0; i < N - 1; i++)
    dist[i] = sensor[i + 1] - sensor[i];
  sort(dist.begin(), dist.end(), greater<>());

  int ans = 0;
  for (int i = K - 1; i < N - 1; i++) ans += dist[i];

  cout << ans << '\n';
}

// N개
// K개 집중국

// 1  3  6  6  7  9

//   2  3  0  1  2