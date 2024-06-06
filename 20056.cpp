//BOJ_20056 마법사 상어와 파이어볼 [골드 4]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M, K;

struct node {
  int r, c; // 좌표
  int m;    // 질량
  int s;    // 속력
  int d;    // 방향

  bool operator<(const node n) const {
    if (this -> r == n.r) return this -> c > n.c;
    return this -> r > n.r;
  };
};

priority_queue<node> pq;
priority_queue<node> tmp;
pair<int, int> dir[8] = {{-1 , 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

void equalProcess() {
  // 2개 이상의 파이어볼이 같은 칸에 있을 경우
  int mSum = 0, sSum = 0;
  int dFlag = -1;   // 홀수면 0, 짝수면 1, 다르면 2
  int len = tmp.size();
  int curr = 0, curc = 0;

  while (!tmp.empty()) {
    auto [r, c, m, s, d] = tmp.top();
    tmp.pop();

    if (!curr && !curc) {
      curr = r;
      curc = c;
    }

    if (dFlag < 0) dFlag = d % 2 == 0;
    else if (dFlag != 2 && dFlag != (int)(d % 2 == 0)) dFlag = 2;

    mSum += m;
    sSum += s;
  }


  mSum /= 5;
  sSum /= len;

  if (!mSum) return;

  if (dFlag == 0 || dFlag == 1) {
    tmp.push({curr, curc, mSum, sSum, 0});
    tmp.push({curr, curc, mSum, sSum, 2});
    tmp.push({curr, curc, mSum, sSum, 4});
    tmp.push({curr, curc, mSum, sSum, 6});
  } else {
    tmp.push({curr, curc, mSum, sSum, 1});
    tmp.push({curr, curc, mSum, sSum, 3});
    tmp.push({curr, curc, mSum, sSum, 5});
    tmp.push({curr, curc, mSum, sSum, 7});
  }
}

void simulate() {
  while(!pq.empty()) {
    auto [r, c, m, s, d] = pq.top();
    pq.pop();

    for (int i = 0; i < s; i++) {
      r += dir[d].first;
      if (r == 0) r = N;
      if (r == N + 1) r = 1;
      c += dir[d].second;
      if (c == 0) c = N;
      if (c == N + 1) c = 1;
    }

    tmp.push({r, c, m, s, d});
  }
  pq = tmp;
  while(!tmp.empty()) tmp.pop();

  // 같은 공간에 있는 거 있는지 체크
  node stn = {0, 0, 0, 0, 0};

  priority_queue<node> res;
  while(!pq.empty()) {
    node cur = pq.top();
    pq.pop();

    if (stn.r == 0) {   // 초기값 설정
      stn = cur;
      continue;
    }

    if (stn.r == cur.r && stn.c == cur.c) {    // 같은 위치에 있다면
      if (tmp.empty()) tmp.push(stn);
      tmp.push(cur);
    } else {
      if (!tmp.empty()) {
        equalProcess();
        stn = cur;
        while (!tmp.empty()) {
          res.push(tmp.top());
          tmp.pop();
        }
      } else {
        res.push(stn);
        stn = cur;
      }
    }
  }
  if (tmp.empty()) res.push(stn);
  if (!tmp.empty()) {
    equalProcess();
    while (!tmp.empty()) {
      res.push(tmp.top());
      tmp.pop();
    }
  }
  pq = res;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M >> K;

  for (int i = 0; i < M; i++) {
    int r, c, m, s, d;
    cin >> r >> c >> m >> s >> d;
    pq.push({r, c, m, s, d});
  }

  while (K--) {
    simulate();
  }

  int res = 0;
  while (!pq.empty()) {
    res += pq.top().m;
    pq.pop();
  }

  cout << res << '\n';
}

// r c 질량 속력 방향

// 7 0 1
// 6 * 2
// 5 4 3 

// 1 * * 2
// * * * *
// * * * *
// * * * *

// 첫번째 이동
// * * (1,2) *
// * * * *
// * * * *
// * * * *
// -> 질량 : (5 + 7 = 12) / 5 = 2
// -> 속력 : (1 + 2 = 3) / 2 = 1
// -> 방향 : 2, 6 모두 짝수 = (0, 2, 4, 6)
// -> (1, 3, 2, 1, 0) (1, 3, 2, 1, 2) (1, 3, 2, 1, 4) (1, 3, 2, 1, 6)

// 두번째 이동
// * 4 * 2
// * * 3 *
// * * * *
// * * 1 *

// 세번째 이동
// (2,4) * * *
// * * * *
// * * (1,3) *
// * * * *
// -> 질량 : (2 + 2 = 4) / 5 = 0 사라짐
// -> 질량 : (2 + 2 = 4) / 5 = 0 사라짐

// * * * *
// * * * *
// * * * *
// * * * *
