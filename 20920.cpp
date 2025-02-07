//BOJ_20920 영단어 암기는 괴로워 [실버 3]
#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct node {
  string word;
  int cnt;
  bool operator<(const node& a) const {
    if (this -> cnt != a.cnt) return this -> cnt < a.cnt;
    if (this -> word.length() != a.word.length())
      return this -> word.length() < a.word.length();
    return this -> word > a.word;
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, M; cin >> N >> M;

  map<string, int> m;
  for (int i = 0; i < N; i++) {
    string str; cin >> str;
    if (str.length() < M) continue;
    m[str]++;
  }

  priority_queue<node> pq;
  for (auto it: m) pq.push({it.first, it.second});

  while (!pq.empty()) {
    auto [word, cnt] = pq.top(); pq.pop();
    cout << word << '\n';
  }
}