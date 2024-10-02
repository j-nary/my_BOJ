//BOJ_15658 연산자 끼워넣기 (2) [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N;
vector<int> number;
int minAns = 1e9 + 10, maxAns = -1e9;

int calc(string curOp) {
  int ret = number[0];
  int idx = 1;
  for (int i = 0; i < curOp.size(); i++) {
    switch(curOp[i]) {
      case '0':
        ret += number[idx++];
        break;
      case '1':
        ret -= number[idx++];
        break;
      case '2':
        ret *= number[idx++];
        break;
      case '3':
        ret /= number[idx++];
        break;
    }
  }
  return ret;
}

void DFS(vector<int> opCnt, string curCnt) {
  if (curCnt.size() == N - 1) {
    int tmp = calc(curCnt);
    minAns = min(minAns, tmp);
    maxAns = max(maxAns, tmp);
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (opCnt[i]) {
      opCnt[i]--;
      DFS(opCnt, curCnt + to_string(i));
      opCnt[i]++;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int ip; cin >> ip;
    number.push_back(ip);
  }

  vector<int> opCnt;   // 덧셈, 뺄셈, 곱셈, 나눗셈
  for (int i = 0; i < 4; i++) {
    int ip; cin >> ip;
    opCnt.push_back(ip);
  }

  DFS(opCnt, "");
  cout << maxAns << '\n';
  cout << minAns << '\n';
}