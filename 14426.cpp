//BOJ_14426 접두사 찾기 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Trie {
  Trie* child[30];
  bool output;

  Trie(): output(false) { fill(child, child + 30, nullptr); }
  ~Trie() { for(int i = 0; i < 30; i++) if (child[i]) delete child[i]; }

  void insert(char* str) {
    if (*str == '\0') { output = true; return; }
    if (!child[*str - 'a']) child[*str - 'a'] = new Trie;
    child[*str - 'a'] -> insert(str + 1);
  }

  bool isPrefix(char* str) {
    if (*str == '\0') return true;
    if (!child[*str - 'a']) return false;
    return child[*str - 'a'] -> isPrefix(str + 1);
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  Trie* root = new Trie;
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    char str[502];
    cin >> str;
    root -> insert(str);
  }

  int ans = 0;
  for (int i = 0; i < M; i++) {
    char str[502];
    cin >> str;
    ans += root -> isPrefix(str);
  }

  cout << ans << '\n';
}