//BOJ_17259 선물이 넘쳐흘러 [골드 5]
#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

struct node {
  int r, c, t;
};

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int B, N, M;
  cin >> B >> N >> M;

  vector<node> v;
  map<pair<int, int>, vector<int>> handle;
  for (int i = 0; i < N; i++) {
    int r, c, t;
    cin >> r >> c >> t;
    if (r == 1 && c == B - 2) {
      handle[{r, c}].push_back(B + 1);
      handle[{r, c}].push_back(B - 1);
    } else if (r == B - 2 && c == B - 2) {
      handle[{r, c}].push_back(2 * B);
      handle[{r, c}].push_back(2 * B - 2);
    } else if (r == 1 && c < B - 2) handle[{r, c}].push_back(c);
    else if (c == B - 2 && (r >= 1 && r <= B - 2)) handle[{r, c}].push_back(B + r);
    else if (r == B - 2 && (c >= 0 && c <= B - 2)) handle[{r, c}].push_back(3 * B - c - 3);
    else continue;
    v.push_back({r, c, t});
  }

  vector<int> timer(N);
  bitset<300> loc;
  bitset<300> mask((1ULL << (3 * B - 3)) - 1);

  int ans = 0;
  while(1) {
    loc = loc << 1;
    if (M) { M--; loc[0] = 1; }
    if ((loc & mask).none()) break;

    for (int i = 0; i < N; i++) if (timer[i]) --timer[i];

    for (int i = 0; i < N; i++) {
      if (timer[i]) continue;      
      auto [r, c, t] = v[i];
      for (auto& boxLoc: handle[{r, c}]) {
        if (loc[boxLoc]) {
          loc[boxLoc] = 0;
          ans++;
          timer[i] = t;
          break;
        }
      }
    }
  }
  cout << ans << '\n';
}