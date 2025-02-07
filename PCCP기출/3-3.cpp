#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int solution(vector<int> menu, vector<int> order, int k) {
    int answer = 0;
    int remainCnt = 0, enterIdx = 0;
    int orderIdx = 1, coffeeTime = menu[order[0]] + 1;
    
    for (int i = 0; orderIdx < order.size(); i++) {
        coffeeTime--;
        if (coffeeTime == 0) {
            remainCnt = max(0, remainCnt - 1);
            coffeeTime = menu[order[orderIdx++]] + 1;
        }
        if (i % k == 0 && enterIdx < order.size()) {
            remainCnt++;
            enterIdx++;
            answer = max(answer, remainCnt);
        }
    }
    return answer;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cout << solution(		{5}, {0, 0, 0, 0, 0}, 5) << '\n';
  // cout << solution(	{5, 12, 30}, {1, 2, 0, 1}, 10) << '\n';
}