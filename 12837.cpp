//BOJ_12837 가계부 (Hard) [골드 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

int N, Q;
int leafSize = 1, arrSize;
vector<ll> arr;

void construct() {
  for (int i = arrSize / 2; i > 0; --i) {
    arr[i] = arr[i * 2] + arr[i * 2 + 1];
  }
}

void update(int i, ll val) {
		// 세그먼트 트리상의 진짜 노드 번호 찾기
    ll idx = leafSize + i - 1;

		arr[idx] += val;
    
		while(idx > 1) {
				idx /= 2;
				arr[idx] = arr[idx * 2] + arr[idx * 2 + 1];
		}
}

ll query(int L, int R, int nodeNum, int nodeL, int nodeR) {
		if (R < nodeL || nodeR < L) return 0;
		
		if (L <= nodeL && nodeR <= R) return arr[nodeNum];
		
		int mid = (nodeL + nodeR) / 2;
		return query(L, R, nodeNum * 2, nodeL, mid) + query(L, R, nodeNum * 2 + 1, mid + 1 ,nodeR);
}


int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> Q;
    while (leafSize < N) leafSize *= 2;
  arrSize = 2 * leafSize - 1;
  arr.resize(arrSize + 1);
    
  for (int i = 0; i < N; i++) {
    ll ip; cin >> ip;
    arr[leafSize + i] = ip;
  }

  construct();

  for (int i = 0; i < Q; i++) {
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