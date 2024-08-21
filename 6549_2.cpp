//BOJ_6549 히스토그램에서 가장 큰 직사각형 [플래티넘 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

int arr[100005];
vector<int> tree;
int N;
int leafSize = 1, treeSize;

void construct() {
  for (int i = treeSize / 2; i > 0; --i) {
    int leftIdx = tree[i * 2];
    int rightIdx = tree[i * 2 + 1];

    if (arr[leftIdx] <= arr[rightIdx]) tree[i] = leftIdx;
    else tree[i] = rightIdx;
  }
}

int query(int L, int R, int nodeNum, int nodeL, int nodeR) {
  if (R < nodeL || nodeR < L) return -1;

  if (L <= nodeL && nodeR <= R) return tree[nodeNum];

  int mid = (nodeL + nodeR) / 2;
  int leftIdx = query(L, R, nodeNum * 2, nodeL, mid);
  leftIdx = max(leftIdx, 0);
  int rightIdx = query(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
  rightIdx = max(rightIdx, 0);
  if (arr[leftIdx] <= arr[rightIdx]) return leftIdx;
  return rightIdx;
}

ll getMax(int L, int R) {
  int M = query(L, R, 1, 1, leafSize);
  ll area = (ll)(R - L + 1) * arr[M];

  if (L < M) {
    area = max(area, getMax(L, M - 1));
  }

  if (M < R) {
    area = max(area, getMax(M + 1, R));
  }

  return area;
}
void test_case() {
  while(leafSize < N) leafSize *= 2;
  treeSize = 2 * leafSize - 1;
  tree.resize(treeSize + 1);
  
  arr[0] = 1e9 + 10;
  for (int i = 0; i < N; i++) {
    cin >> arr[i + 1];
    tree[leafSize + i] = i + 1;
  }

  construct();

  cout << getMax(1, N) << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  while(1) {
    cin >> N;
    if (!N) break;
    tree.clear();
    test_case();
  }
}