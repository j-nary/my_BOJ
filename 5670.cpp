//BOJ_5670 휴대폰 자판 [플래티넘 4]
#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <iomanip>

using namespace std;
using ll = long long;

vector<string> str;

struct Trie {
  Trie *child[30];
  bool output;
  int branch, words;
  
  Trie(): output(false), branch(0), words(0) { fill(child, child + 30, nullptr); }
  ~Trie() { for(int i = 0; i < 30; i++) if (child[i]) delete child[i]; }

  void insert(char *str) {
    if (*str == '\0') {
      branch++;
      output = true;
      return;
    }

    if (!child[*str - 'a']) {
      branch++;
      child[*str - 'a'] = new Trie;
    }
    words++;
    child[*str - 'a'] -> insert(str + 1);
  }

  ll cntTyping(bool isRoot = false) {
    ll res = 0;
    if (isRoot || branch > 1) res = words;

    for (int i = 0; i < 30; i++)
      if (child[i]) res += child[i] -> cntTyping();
    
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N;
  while(cin >> N) {
    Trie *root = new Trie;
    for (int i = 0; i < N; i++) {
      char word[81]; cin >> word;
      root -> insert(word);
    }
    cout << fixed << setprecision(2) << (double)root->cntTyping(true) / N << '\n';
    delete root;
  }
}