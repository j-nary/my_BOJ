//BOJ_2357 최솟값과 최댓값 [골드 1]

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, M;
vector<pair<int, int>> arr;
vector<pair<int, int>> seg;

int leafSize = 1;
int arrSize;
int minRet, maxRet;

void construct() {
  for (int i = arrSize / 2; i > 0; --i) {
    int minValue = min(arr[i * 2].first, arr[i * 2 + 1].first);
    if (!arr[i * 2].first) minValue = arr[i * 2 + 1].first;
    if (!arr[i * 2 + 1].first) minValue = arr[i * 2 + 1].first;

    int maxValue = max(arr[i * 2].second, arr[i * 2 + 1].second);
    
    arr[i] = {minValue, maxValue};
  }
}

void query(int L, int R, int nodeNum, int nodeL, int nodeR) {
  if (R < nodeL || nodeR < L) return;

  if (L <= nodeL && nodeR <= R) {
    minRet = min(minRet, arr[nodeNum].first);
    maxRet = max(maxRet, arr[nodeNum].second);
    return;
  }

  int mid = (nodeL + nodeR) / 2;
  query(L, R, nodeNum * 2, nodeL, mid);
  query(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M;

  while (leafSize < N) leafSize *= 2;
  arrSize = 2 * leafSize - 1;
  arr.resize(arrSize + 1);

  for (int i = 0; i < N; i++) {
    int ip; cin >> ip;
    arr[leafSize + i] = {ip, ip};
  }

  construct();

  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    minRet = 1e9;
    maxRet = 0;
    query(a, b, 1, 1, leafSize);
    cout << minRet << ' ' << maxRet << '\n';
  }
}