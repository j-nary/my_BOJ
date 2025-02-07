#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// To execute C++, please define "int main()"

vector<string> startTime, endTime;
int cnt = 0;
void solution(vector<vector<string>> data) {
  int totalCnt = 0;
  for (auto d: data) {
    int inCnt = stoi(d[1]);
    int outCnt = stoi(d[2]);

    if (inCnt - outCnt == 0) continue;

    totalCnt += (inCnt - outCnt);
    if (cnt < totalCnt) {
      cnt = totalCnt;
      startTime.clear();
      endTime.clear();
      startTime.push_back(d[0]);
    } else if (cnt > totalCnt) {
      if (startTime.size() > endTime.size()) endTime.push_back(d[0]);
    } else {
      startTime.push_back(d[0]);
    }
  }
}

int main() {
  // 1. 방문한 사람 수, 시간
  //    [{count: 방문한 사람 수, time: 시간}]
  // 2. 나가는 경우
  // 3. 시점
  //    가장 바쁜 시간: 더 많은 날 
  //    범용적으로 다 쓸 수 있는 것
  //    

  // 시간으로 정렬된 데이터
  solution({{"2025 02 06 01 50 22", "5", "3"},
            {"2025 02 06 01 50 30", "0", "1"},
            {"2025 02 06 01 50 32", "20", "21"},
            {"2025 02 06 01 50 35", "5", "3"}});

  for (int i = 0; i < startTime.size(); i++) {
    cout << startTime[i] << "부터 " << endTime[i] << "직전까지가 " << cnt << "명이 가장 많이 방문한 시점입니다.\n";
  }
  return 0;
}


