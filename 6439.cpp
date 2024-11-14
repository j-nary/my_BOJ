//BOJ_6439 교차 [골드 1]
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

bool isInside(pii x, pii A, pii B) {
  return min(A.first, B.first) < x.first && x.first < max(A.first, B.first)
      && min(A.second, B.second) < x.second && x.second < max(A.second, B.second);
}

bool test_case() {
  pair<pii, pii> l1;
  cin >> l1.first.first >> l1.first.second >> l1.second.first >> l1.second.second;

  if (l1.first.first > l1.second.first) swap(l1.first, l1.second);
  pii A, B;
  cin >> A.first >> A.second >> B.first >> B.second;

  if (A.first > B.first) swap(A, B);

  pair<pii, pii> r1 = {A, {B.first, A.second}};
  pair<pii, pii> r2 = {{B.first, A.second}, B};
  pair<pii, pii> r3 = {B, {A.first, B.second}};
  pair<pii, pii> r4 = {{A.first, B.second}, A};
  return (isIntersect(l1, r1) || isIntersect(l1, r2) || isIntersect(l1, r3) || isIntersect(l1, r4) ||
          (isInside(l1.first, A, B) && isInside(l1.second, A, B)));
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int tc; cin >> tc;
  for (int t = 1; t <= tc; t++) {
    if (test_case()) cout << "T\n";
    else cout << "F\n";
  }
}