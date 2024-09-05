//BOJ_2268 수들의 합 7 [골드 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

int arrSize, leafSize = 1;
vector<ll> arr;

void update(int i, ll val) {
  int idx = leafSize + i - 1;
  arr[idx] = val;

  while (idx > 1) {
    idx /= 2;
    arr[idx] = arr[idx * 2] + arr[idx * 2 + 1];
  }
}

ll query(int L, int R, int nodeNum, int nodeL, int nodeR) {
  if (R < nodeL || nodeR < L) return 0;

  if (L <= nodeL && nodeR <= R) return arr[nodeNum];

  int mid = (nodeL + nodeR) / 2;
  return query(L, R, nodeNum * 2, nodeL, mid) + query(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, M;
  cin >> N >> M;

  while (leafSize < N) leafSize *= 2;
  arrSize = 2 * leafSize - 1;
  arr.resize(arrSize + 1);

  for (int i = 0; i < M; i++) {
    int option, first, second;
    cin >> option >> first >> second;

    if (!option) cout << query(min(first, second), max(first, second), 1, 1, leafSize) << '\n';
    else update(first, second);
  }
}