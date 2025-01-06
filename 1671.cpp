//BOJ_1671 상어의 저녁식사 [플래티넘 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct shark {
  long long sz, sp, ig;   // 크기, 속도, 지능
  int idx;                // 입력받은 순서
  bool operator< (const shark& s) const {
    if (sz >= s.sz && sp >= s.sp && ig >= s.ig) {
      if (sz == s.sz && sp == s.sp && ig == s.ig) return idx > s.idx;
      return false;
    }
    return true;
  }
};

int N;
int A[102], B[51];
bool chk[102];
vector<int> adj[102];

bool dfs(int a) {
  chk[a] = true;
  for (int b: adj[a]) {
    if (B[b] == -1 || !chk[B[b]] && dfs(B[b])) {
      A[a] = b;
      B[b] = a;
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  memset(A, -1, sizeof(A));
  memset(B, -1, sizeof(B));
  
  cin >> N;
  vector<shark> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i].sz >> S[i].sp >> S[i].ig;
    S[i].idx = i;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j || S[i] < S[j]) continue;
      adj[i].push_back(j);
      adj[i + N].push_back(j);
    }
  }

  int matchingCnt = 0;
  for (int i = 0; i < 2 * N; i++) {
    if (A[i] != -1) continue;
    memset(chk, false, sizeof(chk));
    matchingCnt += dfs(i);
  }

  cout << N - matchingCnt << '\n';
}