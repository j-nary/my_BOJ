//BOJ_2243 사탕상자 [플래티넘 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

vector<ll> arr;
ll leafSize = 1, arrSize;

void construct() {
  for (int i = arrSize / 2; i > 0; --i) arr[i] = arr[i * 2] + arr[i * 2 + 1];
}

void update(int i, ll val) {
  ll idx = leafSize + i - 1;
  arr[idx] = val;
  while(idx > 1) {
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

  int N; cin >> N;

  while (leafSize < N) leafSize *= 2;
  arrSize = 2 * leafSize - 1;
  arr.resize(arrSize + 1);

  for ()
  int query[100005][3];
  for (int i = 0; i < N; i++) {
    cin >> query[i][0];
    switch(query[i][0]) {
      case 1:   // 꺼낼 사탕의 순위
        cin >> query[i][1];
      case 2:   // 넣을 사탕의 맛, 사탕의 개수(+ 넣기, - 빼기)
        cin >> query[i][2];
    }
  }


}