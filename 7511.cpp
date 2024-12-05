//BOJ_7511 소셜 네트워킹 어플리케이션 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int parent[1000006];

int find(int N) {
  if (parent[N] < 0) return N;
  return parent[N] = find(parent[N]);
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  parent[b] = a;
}

void test_case() {
  memset(parent, -1, sizeof(parent));

  int N; cin >> N;  // 유저의 수
  int K; cin >> K;  // 관계의 수
  for (int i = 0; i < K; i++) {
    int a, b; cin >> a >> b;
    merge(a, b);
  }

  int M; cin >> M;
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    if (find(u) == find(v)) cout << "1\n";
    else cout << "0\n";
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int tc; cin >> tc;
  for (int t = 1; t <= tc; t++) {
    cout << "Scenario " << t << ":\n";
    test_case();
    cout << '\n';
  }
}