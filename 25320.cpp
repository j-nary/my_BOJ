#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

bool chk[200005];

struct node {
  int number; bool action;  // 0은 BLOCK, 1은 CHAIN
  bool operator<(const node a) const {
    return this -> number > a.number;
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, M;
  cin >> N >> M;
  priority_queue<node> A;
  priority_queue<node> B;

  for (int i = 0; i < M; i++) {
    char robot; string action; int number;
    cin >> robot >> action >> number;
    chk[number] = true;
    if (robot == 'A') A.push({number, 0});
    else B.push({number, 0});
  }

  char robot;
  if (N % 2) robot = 'B';
  else robot = 'A';

  vector<string> ans;
  for (int i = 1; i <= 2 * N; i++) {
    if (chk[i]) continue;

    if (robot == 'A') {
      auto [number, action] = A.top(); A.pop();
      if (number > i) {
        cout << "NO" << '\n';
        return 0;
      }

      if (!action) {  // BLOCK
        ans.push_back("A BLOCK " + to_string(number));
        B.push({i, 1});
      } else {
        ans.push_back("A CHAIN " + to_string(number));
        B.push({i, 0});
      }
      robot = 'B';
    } else {
      auto [number, action] = B.top(); B.pop();
      if (number > i) {
        cout << "NO" << '\n';
        return 0;
      }

      if (!action) {
        ans.push_back("B BLOCK " + to_string(number));
        A.push({i, 1});
      } else {
        ans.push_back("B CHAIN " + to_string(number));
        A.push({i, 0});
      }
      robot = 'A';
    }
  }

  string act;
  while (!A.empty() && !B.empty()) {
    if (robot == 'A') {
      auto [number, action] = A.top(); A.pop();
      act = action ? "CHAIN" : "BLOCK";
      ans.push_back("A " + act + " " + to_string(number));
      auto [number2, action2] = B.top(); B.pop();
      act = action2 ? "CHAIN" : "BLOCK";
      ans.push_back("B " + act + " " + to_string(number2));
    } else {
      auto [number, action] = B.top(); B.pop();
      act = action ? "CHAIN" : "BLOCK";
      ans.push_back("B " + act + " "+ to_string(number));
      auto [number2, action2] = A.top(); A.pop();
      act = action2 ? "CHAIN" : "BLOCK";
      ans.push_back("A " + act + " " + to_string(number2));
    }
  }

  if (A.size() > 1 || B.size() > 1) {
    cout << "NO\n";
    return 0;
  }

  while (!A.empty()) {
    auto [number, action] = A.top(); A.pop();
    act = action ? "CHAIN" : "BLOCK";

    ans.push_back("A " + act + " " + to_string(number));
  }

  while (!B.empty()) {
    auto [number, action] = B.top(); B.pop();
    act = action ? "CHAIN" : "BLOCK";

    ans.push_back("B " + act + " " + to_string(number));
  }

  cout << "YES\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << '\n';
  }
}