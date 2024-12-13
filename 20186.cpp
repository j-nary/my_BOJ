//BOJ_20186 수 고르기 [실버 4]

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, K;
bool chk[5003];

struct node {
  int val, idx;

  bool operator<(const node& a) const {
    if (this->val == a.val) return this->idx < a.idx;
    return this->val > a.val;
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> K;
  vector<node> sortedV;
  for (int i = 0; i < N; i++) {
    int ip; cin >> ip;
    sortedV.push_back({ip, i});
  }

  sort(sortedV.begin(), sortedV.end());

  long long ans = 0;

  for (int i = 0; i < K; i++) chk[sortedV[i].idx] = true;

  for (int i = 0; i < K; i++) {
    ans += sortedV[i].val;
    int cnt = 0;
    for (int j = 0; j < sortedV[i].idx; j++) if (chk[j]) cnt++;
    ans -= cnt;
  }

  cout << ans << '\n';
}