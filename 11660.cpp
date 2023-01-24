//BOJ_11660 구간 합 구하기 5
//https://www.acmicpc.net/problem/11660
//시간 초과 -> 알고리즘 분류 보니 DP네. 다시 접근하자.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;
    //표의 크기 N, 구해야 하는 횟수 M

    vector<int> v;
    for (int i = 0; i < N*N; i++) {
        int input; cin >> input;
        v.push_back(input);
    }

    for (int tc = 0; tc < M; tc++) {
        int x1, y1; cin >> x1 >> y1;
        int x2, y2; cin >> x2 >> y2;

        int start = (x1 * N) - (N - y1) - 1;
        int sum = 0;
        
        for (int i = 0; i <= x2 - x1; i++) {
            int idx = start + (i * N);
            for (int j = 0; j <= y2- y1; j++) {
                // sum += v[idx + j];
                int value = v[idx + j];
                sum += value;
            }
        }

        cout << sum << endl;
    }
}

// 1 2 3 4
// 2 3 4 5
// 3 4 5 6
// 4 5 6 7

// 0  1  2  3
// 4  5  6  7
// 8  9  10 11
// 12 13 14 15

// 2,2 -> 5
// 2*4 -(4-2) -1 = 8 -2 -1 = 5

// (y2-y1-1) 4-2-1번

// 3,4 -> 11
// 3*4 - (4-4) -1 = 11