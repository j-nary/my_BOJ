//BOJ_1149 RGB거리 [실버 1]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int house[1003][3];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> house[i][0];
        cin >> house[i][1];
        cin >> house[i][2];
    }

    for (int i = 1; i < N; i++) {
        house[i][0] += min(house[i-1][1], house[i-1][2]);
        house[i][1] += min(house[i-1][0], house[i-1][2]);
        house[i][2] += min(house[i-1][0], house[i-1][1]);
    }

    int res = min(house[N-1][0], house[N-1][1]);
    cout << min(res, house[N-1][2]) << endl;
}