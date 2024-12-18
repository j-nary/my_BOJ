//BOJ_13306 트리 [플래티넘 4]
#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAX = 200005;
int N, Q;
int tree[MAX];
int query[MAX * 2][3];

int parent[MAX];
int find(int a) {
  if (parent[a] < 0) return a;
  return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a != b) parent[b] = a;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  memset(parent, -1, sizeof(parent));
  
  cin >> N >> Q; Q += N - 1;
  for (int i = 2; i <= N; i++) cin >> tree[i];

  // 쿼리 저장
  for (int i = 0; i < Q; i++) {
    cin >> query[i][0];
    switch(query[i][0]) {
      case 0:
        cin >> query[i][1];
        continue;
      case 1:
        cin >> query[i][1] >> query[i][2];
    }
  }

  // 쿼리 거꾸로 풀 것이기에 정답도 거꾸로 출력 (선입후출)
  stack<bool> res;
  for (int i = Q - 1; i >= 0; i--) {
    switch(query[i][0]) {
      case 0:
        // 본래 자신의 부모였던 정점과 연결
        merge(query[i][1], tree[query[i][1]]);
        continue;
      case 1:
        // 쿼리의 경우 두 정점이 같은 집합 내에 있는지 확인
        int u = find(query[i][1]), v = find(query[i][2]);
        res.push(u == v);
    }
  }

  while(!res.empty()) {
    cout << (res.top() ? "YES\n" : "NO\n");
    res.pop();
  }
}