//BOJ_1967 트리의 지름 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct node {
  int num, weight;
};
int N;
vector<node> T[100005];
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int p, c, w; cin >> p >> c >> w;
    T[p].push_back({c, w});
    T[c].push_back({p, w});
  }

  
}