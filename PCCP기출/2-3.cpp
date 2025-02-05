#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    set<int> cnt[102][102];
    set<int> chk[102][102];

    for (auto route: routes) {
      pair<int, int> S = {points[route[0] - 1][0], points[route[0] - 1][1]};
      int time = 0;
      
      if (!chk[S.first][S.second].count(time)) {
        if (cnt[S.first][S.second].count(time)) {
          answer++;
          chk[S.first][S.second].insert(time);
        } else cnt[S.first][S.second].insert(time);
      }

      for (int i = 1; i < route.size(); i++) {
        pair<int, int> E = {points[route[i] - 1][0], points[route[i] - 1][1]};

        while(!(S.first == E.first && S.second == E.second)) {
          time++;
          if (S.first != E.first) {
            if (S.first < E.first) S.first++;
            else if (S.first > E.first) S.first--;
          } else {
            if (S.second < E.second) S.second++;
            else if (S.second > E.second) S.second--;
          }
          if (chk[S.first][S.second].count(time)) continue;
          if (cnt[S.first][S.second].count(time)) {
            answer++;
            chk[S.first][S.second].insert(time);
          } else cnt[S.first][S.second].insert(time);
        }
      }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cout << solution({{3, 2}, {6, 4}, {4, 7}, {1, 4}}, {{4, 2}, {1, 3}, {2, 4}}) << '\n';
    cout << solution({{3, 2}, {6, 4}, {4, 7}, {1, 4}}, {{4, 2}, {1, 3}, {4, 2}, {4, 3}}) << '\n';
    cout << solution({{2, 2}, {2, 3}, {2, 7}, {6, 6}, {5, 2}}, {{2, 3, 4, 5}, {1, 3, 4, 5}}) << '\n';
    
}