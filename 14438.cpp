//BOJ_14428 수열과 쿼리 17 [골드 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

vector<pair<ll, int>> arr;
int arrSize, leafSize = 1;

void construct() {
  for (int i = arrSize / 2; i > 0; --i) {
    if (!arr[i * 2].first || !arr[i * 2 + 1].first) arr[i] = max(arr[i * 2], arr[i * 2 + 1]);
    else arr[i] = min(arr[i * 2], arr[i * 2 + 1]);
  }
}

void update(int i, int val) {
  int idx = leafSize + i - 1;
  arr[idx].first = (ll)val;

  while(idx > 1) {
    idx /= 2;
    if (!arr[idx * 2].first || !arr[idx * 2 + 1].first) arr[idx] = max(arr[idx * 2], arr[idx * 2 + 1]);
    else arr[idx] = min(arr[idx * 2], arr[idx * 2 + 1]);
  }
}

pair<ll, int> query(int L, int R, int nodeNum, int nodeL, int nodeR) {
  if (R < nodeL || L > nodeR) return {0, 0};
  if (L <= nodeL && nodeR <= R) return arr[nodeNum];

  int mid = (nodeL + nodeR) / 2;
  pair<ll, int> leftQuery = query(L, R, nodeNum * 2, nodeL, mid);
  pair<ll, int> rightQuery = query(L, R, nodeNum * 2 + 1, mid + 1, nodeR);

  if (!leftQuery.first || !rightQuery.first) return max(leftQuery, rightQuery);
  return min(leftQuery, rightQuery);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N;
  cin >> N;

  while (leafSize < N) leafSize *= 2;
  arrSize = leafSize * 2 - 1;
  arr.resize(arrSize);

  for (int i = 0; i < N; i++) {
    ll input; cin >> input;
    arr[leafSize + i] = {input, i + 1};
  }

  construct();

  int M;
  cin >> M;

  for (int i = 0; i < M; i++) {
    int option, p, q;
    cin >> option >> p >> q;

    if (option == 1) {
      update(p, q);
    } else {
      cout << query(p, q, 1, 1, leafSize).first << '\n';
    }
  }
}