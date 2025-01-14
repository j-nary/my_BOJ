//BOJ_14725 개미굴 [골드 3]
#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int N;

struct Trie {
  map<string, Trie*> child;

  void insert(vector<string>& inputs, int idx) {
    if (idx == inputs.size()) return;
    if (child.find(inputs[idx]) == child.end()) child[inputs[idx]] = new Trie();
    child[inputs[idx]] -> insert(inputs, idx + 1);
  }

  void output(int depth) {
    for (auto& ch: child) {
      for (int i = 0; i < depth; i++) cout << "--";
      cout << ch.first << '\n';
      ch.second -> output(depth + 1);
    }
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;

  Trie* root = new Trie();

  for (int i = 0; i < N; i++) {
    int K; cin >> K;
    vector<string> inputs(K);
    for (int j = 0; j < K; j++) cin >> inputs[j];
    root -> insert(inputs, 0);
  }

  root -> output(0);
}