//BOJ_1700 멀티탭 스케줄링 [골드 1]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int order[1003];
bool chk[1003];
vector<int> plug;

int N, K;

void exchange(int idx) {
  int farIdx, dist = 0;
  for (int i = 0; i < plug.size(); i++) {
    int tmp = find(order + idx, order + K, plug[i]) - order;
    if (dist < tmp) { dist = tmp; farIdx = i; };
  }
  plug[farIdx] = order[idx];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> K;
  for (int i = 0; i < K; i++) cin >> order[i];

  int ans = 0;
  for (int i = 0; i < K; i++) {
    if (find(plug.begin(), plug.end(), order[i]) != plug.end()) continue;

    if (plug.size() < N) plug.push_back(order[i]);
    else { exchange(i); ans++; }
  }

  cout << ans << '\n';
}