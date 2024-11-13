//BOJ_17386 선분 교차 1 [골드 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

using ll = long long;

#define pii pair<ll,ll>

ll ccw(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3) {
		ll s = p1.first*p2.second + p2.first*p3.second + p3.first*p1.second;
		s -= (p1.second*p2.first + p2.second*p3.first + p3.second*p1.first);
		if (s > 0) return 1;
		if (s == 0) return 0;
		return -1;
}

bool isIntersect(pair<pii, pii> l1, pair<pii, pii> l2) {
		pii p1 = l1.first;
		pii p2 = l1.second;
		pii p3 = l2.first;
		pii p4 = l2.second;
		
		ll p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
		ll p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

		// 두 직선이 일직선 상에 존재
	  if (p1p2 == 0 && p3p4 == 0) {
				if (p1 > p2) swap(p1, p2);
				if (p3 > p4) swap(p3, p4);

				// 두 선분이 포개져있는지 확인
				return p3 <= p2 && p1 <= p4;
		}
		return p1p2 <= 0 && p3p4 <= 0;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  pair<pii, pii> l1, l2;
  cin >> l1.first.first >> l1.first.second >> l1.second.first >> l1.second.second;
  cin >> l2.first.first >> l2.first.second >> l2.second.first >> l2.second.second;

  cout << isIntersect(l1,l2)<<'\n';
}