//BOJ_1017 소수 쌍 [플래티넘 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAX = 1003;
vector<int> adj[MAX];
int A[MAX], B[MAX];
bool chk[MAX];
bool isPrime[2003];
int firstNum;

bool dfs(int a) {
  if (a == firstNum) return false;
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

  memset(isPrime, true, sizeof(isPrime));
  isPrime[1] = false;
  for (int i = 2; i * i <= 2003; i++) {
    if (!isPrime[i]) continue;
    for (int j = i * i; j <= 2003; j+=i) isPrime[j] = false;
  }

  int N; cin >> N;
  if (N % 2) { cout << -1 << '\n'; return 0; }
  
  vector<int> v(N);
  for (int i = 0; i < N; i++) cin >> v[i];
  firstNum = v[0];

  for (int i = 0; i < N; i++) {
    if (v[i] % 2 != firstNum % 2) continue;
    for (int j = 0; j < N; j++) {
      if (i == j || v[j] % 2 == firstNum % 2 || !isPrime[v[i] + v[j]]) continue;
      adj[v[i]].push_back(v[j]);
    }
  }

  vector<int> ans;
  for (int firstMatching: adj[firstNum]) {
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));

    A[firstNum] = firstMatching;
    B[firstMatching] = firstNum;

    int matchingCnt = 1;
    for (int i = 1; i < N; i++) {
      if (v[i] % 2 != firstNum % 2 || A[v[i]] != -1) continue;
      memset(chk, false, sizeof(chk));
      matchingCnt += dfs(v[i]);
    }

    if (matchingCnt == N / 2) ans.push_back(firstMatching);
  }

  if (ans.empty()) { cout << -1 << '\n'; return 0; }
  sort(ans.begin(), ans.end());
  for (int a: ans) cout << a << ' ';
  cout << '\n';
}