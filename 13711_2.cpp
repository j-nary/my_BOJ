// BOJ_13711 LCS 4 [플래티넘 5]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int seq1[100005], seq2[100005], N;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    int ip; cin >> ip;
    seq1[ip] = i;
  }

  for (int i = 1; i <= N; i++) {
    int ip; cin >> ip;
    seq2[i] = seq1[ip];
  }
  
  vector<int> LIS;
  LIS.push_back(seq2[1]);
  for (int i = 2; i <= N; ++i) {
    int idx = lower_bound(LIS.begin(), LIS.end(), seq2[i]) - LIS.begin();
    if (idx == LIS.size()) LIS.push_back(seq2[i]);
    else LIS[idx] = seq2[i];
  }
  cout << LIS.size() << '\n';
}