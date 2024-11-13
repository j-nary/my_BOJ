//BOJ_2162 선분 그룹 [플래티넘 5]
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

int parent[3003];
vector<int> ans(3003);
int find(int idx) {
  if (parent[idx] < 0) return idx;
  return parent[idx] = find(parent[idx]);
}

void merge(int idx1, int idx2) {
  idx1 = find(idx1);
  idx2 = find(idx2);
  if (idx1 == idx2) return;
  parent[idx2] = idx1;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;

  vector<pair<pii, pii>> v;
  for (int i = 0; i < N; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    v.push_back({{x1, y1}, {x2, y2}});
  }

  memset(parent, -1, sizeof(parent));
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (isIntersect(v[i], v[j])) merge(i, j);
    }
  }
  

  for (int i = 0; i < N; i++) ans[find(i)]++;
  int cnt;
  sort(ans.begin(), ans.end(), greater<>());
  for (int i = 0; i < N; i++) {
    if (ans[i] == 0) break;
    cnt = i + 1;
  }
  cout << cnt << '\n' << ans[0] << '\n';
}