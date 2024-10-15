//BOJ_18353 병사 배치하기 [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> LIS;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N;
  cin >> N;
  vector<int> Arr(N);
  for (int i = 0; i < N; i++) {
    cin >> Arr[i];
  }
  reverse(Arr.begin(), Arr.end());
  LIS.push_back(Arr[0]);
  for (int i = 1; i < N; ++i) {
    int idx = lower_bound(LIS.begin(), LIS.end(), Arr[i]) - LIS.begin();
    if (idx == LIS.size()) LIS.push_back(Arr[i]);
    else LIS[idx] = Arr[i];
  }

  int ans = N - LIS.size();
  cout << ans << '\n';
}