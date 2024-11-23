//BOJ_6886 절사평균 [실버 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, K;
  cin >> N >> K;

  vector<double> v(N);
  for (int i = 0; i < N; i++) cin >> v[i];

  sort(v.begin(), v.end());

  double sum = 0, scale = pow(10, 2);
  for (int i = K; i < N - K; i++) sum += v[i];
  sum /= (N - 2 * K);
  printf("%.2lf\n", sum + 0.000000001);

  sum = 0;
  for (int i = K; i < N - K; i++) {
    if (i == K || i == N - K - 1) sum += (v[i] * (K + 1));
    else sum += v[i];
  }
  sum /= N;
  printf("%.2lf\n", sum + 0.000000001);
}