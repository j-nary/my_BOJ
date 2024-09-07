//BOJ_25966 배찬우는 배열을 좋아해 [실버 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, M, q;
int arr[3003][3003];
int rowOrder[3003];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M >> q;

  for (int i = 0; i < N; i++) {
    rowOrder[i] = i;
    for (int j = 0; j < M; j++) {
      cin >> arr[i][j];
    }
  }

  for (int qCnt = 0; qCnt < q; qCnt++) {
    int option; cin >> option;
      int i, j, k;
    if (option) {
      cin >> i >> j;
      swap(rowOrder[i], rowOrder[j]);
    } else {
      cin >> i >> j >> k;
      arr[rowOrder[i]][j] = k;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << arr[rowOrder[i]][j] << ' ';
    }
    cout << '\n';
  }
}