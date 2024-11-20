//BOJ_24891 단어 마방진 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int L, N;
bool chk[21];
vector<string> word;
vector<string> ans, real_ans;

bool isMagicSquare() {
  int len = ans.size();
  if (len < 2) return true;

  for(int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (ans[i][j] != ans[j][i]) return false;
    }
  }

  return true;
}

void backtrack() {
  if (ans.size() == L) {
    if (real_ans.empty()) real_ans = ans;
    return;
  }

  for (int i = 0; i < N; i++) {
    if (chk[i]) continue;

    ans.push_back(word[i]);
    if (!isMagicSquare()) { ans.pop_back(); continue; }

    chk[i] = true;
    backtrack();
    chk[i] = false;
    ans.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  cin >> L >> N;
  for (int i = 0; i < N; ++i) {
    string ip; cin >> ip;
    word.push_back(ip);
  }
  sort(word.begin(), word.end());
  backtrack();
  if (real_ans.empty()) cout << "NONE\n";
  else for (int i = 0; i < L; ++i) cout << real_ans[i] << '\n';
}