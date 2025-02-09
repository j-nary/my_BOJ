#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> play_list, int listen_time) {
    int n = play_list.size();
    int maxUnique = 0, left = 0, totalTime = 0;
    unordered_set<int> songSet;

    // 원형 리스트이므로 2배 크기까지 탐색
    for (int right = 0; right < 2 * n; right++) {
        int song = play_list[right % n];
        songSet.insert(song);
        totalTime += song;

        // 총 재생 시간이 listen_time을 초과하면 왼쪽 포인터를 조정
        while (totalTime > listen_time) {
            totalTime -= play_list[left % n];
            if (songSet.count(play_list[left % n]) == 1) {
                songSet.erase(play_list[left % n]);
            }
            left++;
        }

        maxUnique = max(maxUnique, (int)songSet.size());
    }

    return maxUnique;
}

int main() {
    vector<int> play_list = {2, 3, 1, 4};
    int listen_time = 3;
    cout << "최대 들을 수 있는 곡 개수: " << solution(play_list, listen_time) << endl;
    return 0;
}