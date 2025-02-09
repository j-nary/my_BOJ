#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> play_list, int listen_time) {
    int n = play_list.size();

    int minElem = play_list[min_element(play_list.begin(), play_list.end()) - play_list.begin()];
    if (listen_time <= minElem) return 1;

    int sum = 0;
    for (int list: play_list) sum += list;
    if (sum <= listen_time) return n;
    
    vector<int> prefixSum(n * 2);
    prefixSum[0] = play_list[0];
    for (int i = 1; i < n * 2; i++) prefixSum[i] = play_list[i % n] + prefixSum[i - 1];

    int mxTime = prefixSum[n * 2 - 1];
    vector<int> time(mxTime + 1);
    int idx = 0;
    for (int i = 0; i <= mxTime; i++) {
      if (prefixSum[idx] < i) idx++;
      time[i] = idx % n;
    }

    int mxWindow = 0;
    for (int i = 0; i <= mxTime / 2; i++) {
      set<int> s;
      for (int j = 0; j < listen_time; j++) {
        s.insert(time[i + j]);
      }
      mxWindow = max(mxWindow, (int)(s.size()));
    }
    return mxWindow;
}

int main() {
    // vector<int> play_list = {2, 3, 1, 4};
    // int listen_time = 3;

    // vector<int> play_list = {5, 10, 15, 20};
    // int listen_time = 1;

    // vector<int> play_list = {2, 3, 5};
    // int listen_time = 15;

    // vector<int> play_list = {1, 1, 1, 1, 1};
    // int listen_time = 3;

    // vector<int> play_list = {4, 5, 6};
    // int listen_time = 5;

        vector<int> play_list = {1, 2, 3, 4};
    int listen_time = 20;

    cout << "최대 들을 수 있는 곡 개수: " << solution(play_list, listen_time) << endl;
    return 0;
}
