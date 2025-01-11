//BOJ_1700 멀티탭 스케줄링 [골드 1]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int cnt[1003], order[1003], usedCnt[1003];
bool chk[1003];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, K; cin >> N >> K;
  for (int i = 0; i < K; i++) { cin >> order[i]; cnt[order[i]]++; }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  int initCnt = 0;
  for (int i = 0; i < K; i++) {

    usedCnt[order[i]]++;
    if (chk[order[i]]) {
      vector<int> tmp;
      while(!pq.empty()) {
        int plug = pq.top().second; pq.pop();
        if (plug == order[i]) break;
        tmp.push_back(plug);
      }
      pq.push({cnt[order[i]] - usedCnt[order[i]], order[i]});
      for (int t: tmp) pq.push({cnt[t] - usedCnt[t], t});
      continue;
    }

    initCnt++;
    chk[order[i]] = true;
    pq.push({cnt[order[i]] - usedCnt[order[i]], order[i]});

    if (initCnt == N) { initCnt = i + 1; break; }
  }

  int ans = 0;

  for (int i = initCnt; i < K; i++) {
    usedCnt[order[i]]++;
    if (chk[order[i]]) {
      vector<int> tmp;
      while(!pq.empty()) {
        int plug = pq.top().second; pq.pop();
        if (plug == order[i]) break;
        tmp.push_back(plug);
      }
      pq.push({cnt[order[i]] - usedCnt[order[i]], order[i]});
      for (int t: tmp) pq.push({cnt[t] - usedCnt[t], t});
      continue;
    }

    ans++;
    int off = pq.top().second; pq.pop();
    chk[order[i]] = true;
    chk[off] = false;
    pq.push({cnt[order[i]] - usedCnt[order[i]], order[i]});
  }

  cout << ans << '\n';
}