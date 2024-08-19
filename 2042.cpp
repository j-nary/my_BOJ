// BOJ_2042 구간 합 구하기 [골드 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

int N, M, K;
vector<ll> arr;
ll leafSize = 1;
ll arrSize;

void construct() {
  for (int i = arrSize / 2; i > 0; --i) {
    arr[i] = arr[i * 2] + arr[i * 2 + 1];
  }
}

void update(int i, ll val) {
		// 세그먼트 트리상의 진짜 노드 번호 찾기
    ll idx = leafSize + i - 1;

		arr[idx] = val;
    
		while(idx > 1) {
				idx /= 2;
				arr[idx] = arr[idx * 2] + arr[idx * 2 + 1];
		}
}

ll query(int L, int R, int nodeNum, int nodeL, int nodeR) {
		// L, R: 구하고자 하는 구간
		// nodeL, nodeR: 해당 노드가 포함하는 구간
		
		// [nodeL, nodeR], [L, R] 이 전혀 안 겹치는 경우
		if (R < nodeL || nodeR < L) return 0;
		
		// [nodeL, nodeR], [L, R] 에 완전히 포함되는 경우
		// 구간 크기가 1인 경우도 자동 포함
		if (L <= nodeL && nodeR <= R) return arr[nodeNum];
		
		// 구간 양분해서 각각 재귀호출해서 더하기
		int mid = (nodeL + nodeR) / 2;
		return query(L, R, nodeNum * 2, nodeL, mid) + query(L, R, nodeNum * 2 + 1, mid + 1 ,nodeR);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  // 수의 개수, 수의 변경이 일어나는 횟수, 구간의 합을 구하는 횟수
  cin >> N >> M >> K;

  while (leafSize < N) leafSize *= 2;
  arrSize = 2 * leafSize - 1;
  arr.resize(arrSize + 1);
    
  for (int i = 0; i < N; i++) {
    ll ip; cin >> ip;
    arr[leafSize + i] = ip;
  }

  construct();

  for (int i = 0; i < M + K; i++) {
    int option;
    ll p, q;
    cin >> option >> p >> q;

    switch(option) {
      // p번째 수를 q로 변경
      case 1:
        update(p, q);
        break;
      
      // p번째 수부터 q번째 수까지의 합
      case 2:
        cout << query(p, q, 1, 1, leafSize) << '\n';
        break;
    }
  }
}