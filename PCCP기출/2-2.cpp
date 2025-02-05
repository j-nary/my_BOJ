#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long simulatePuzzle(long long level, vector<int>& diffs, vector<int>& times) {
    long long timeTaken = 0;
    for (int i = 0; i < diffs.size(); i++) {
        int diff= diffs[i], time = times[i];

        if (diff <= level) timeTaken += time;
        else if (i > 0) timeTaken += time + (diff - level) * (time + times[i - 1]);
        else timeTaken += (diff - level) * (time + i == 0 ? 1 : times[i - 1]) + time;
    }

    return timeTaken;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    long long left = 1, right = *max_element(diffs.begin(), diffs.end()), ans = LLONG_MAX;
    while (left <= right) {
      long long mid = (left + right) / 2;
      if (simulatePuzzle(mid, diffs, times) <= limit) {
        right = mid - 1;
        ans = min(ans, mid);
      } else {
        left = mid + 1;
      }
    }
    return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cout << solution({1, 5, 3}, {2, 4, 7}, 30) << '\n';
  cout << solution({1, 4, 4, 2}, {6, 3, 8, 2}, 59) << '\n';
  cout << solution({1, 328, 467, 209, 54}, {2, 7, 1, 4, 3}, 1723) << '\n';
  cout << solution({1, 99999, 100000, 99995}, {9999, 9001, 9999, 9001}, 3456789012) << '\n';
}