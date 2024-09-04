//BOJ_16139 인간-컴퓨터 상호작용 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string str;

vector<int> preSum[30];
int solve() {
  char a; cin >> a;
  int l, r; cin >> l >> r;

  if (!l) return preSum[a - 'a'][r];
  return preSum[a - 'a'][r] - preSum[a -'a'][l - 1];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> str;

  int len = str.length();

  for (int i = 0; i < 30; i++) {
    preSum[i].resize(len, 0);
  }

  for (int i = 0; i < len; i++) {
    if (!i) {
      preSum[str[i] - 'a'][i] = 1;
      continue;
    }

    for (int j = 0; j < 26; j++) {
      preSum[j][i] = preSum[j][i - 1] + (str[i] - 'a' == j);
    }
  }
  int qCnt; cin >> qCnt;
  while(qCnt--) cout << solve() << '\n';
}