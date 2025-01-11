//BOJ_1493 박스 채우기 [골드 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<pair<int, int>> cube;
int N, ans;
bool isFail;

void divideConquer(int l, int w, int h, int idx) {
  if (!l || !w || !h) return;

  for (int i = idx; i < N; i++) {
    if (cube[i].second <= 0) continue;

    if (l < cube[i].first || w < cube[i].first || h < cube[i].first) continue;

    cube[i].second--;
    ans++;

    divideConquer(cube[i].first, w - cube[i].first, cube[i].first, idx);
    divideConquer(l - cube[i].first, w, cube[i].first, idx);
    divideConquer(l, w, h - cube[i].first, idx);

    return;
  }

  isFail = true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int length, width, height;
  cin >> length >> width >> height;

  cin >> N;
  for (int i = 0; i < N; i++) {
    int len, cnt; cin >> len >> cnt;
    cube.push_back({1 << len, cnt});
  }

  sort(cube.begin(), cube.end(), greater<>());

  divideConquer(length, width, height, 0);
  if (isFail) cout << -1 << '\n';
  else cout << ans << '\n';
}