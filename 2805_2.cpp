//BOJ_2805 나무 자르기 [실버 2]
//https://www.acmicpc.net/problem/2805
//6개월만의 재도전 -> 시간초과

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; //나무의 수와 가져가려는 나무 길이
    cin >> N >> M;
    vector<int> tree;
    for (int i = 0; i < N; i++) {
        int len; cin >> len;
        tree.push_back(len);
    }

    sort(tree.begin(), tree.end());
    int height = tree[tree.size() - 1] - 1;
    while(1) {
        int have = 0;
        for (int i = 0; i < tree.size(); i++) {
            int stn = tree[i] - height;
            if (stn > 0) have += stn;
        }

        if (have >= M) {
            break;
        }
        height--;
    }

    cout << height << endl;
}