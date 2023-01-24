//BOJ_9465 스티커 [실버 1]
//https://www.acmicpc.net/problem/9465
//출발점 잡고 DFS로 가자

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sticker[2][100005];
int n;
int maxSum;
void DFS(vector<int> v, int x, int y) {
    if (y == n-1) {
        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += v[i];
        }
        if (maxSum < sum) maxSum = sum;
        return;
    }

    if (x == 0) {
        v.push_back(sticker[1][y + 1]);
        DFS(v, 1, y + 1);
        if (y != n-2) {
            v[v.size() - 1] = sticker[1][y + 2];
            DFS(v, 1, y + 2);
        }
    }
    else {
        v.push_back(sticker[0][y + 1]);
        DFS(v, 0, y + 1);
        if (y != n-2) {
            v[v.size() - 1] = sticker[0][y + 2];
            DFS(v, 0, y + 2);
        }
    }

}
void test_case() {
    cin >> n;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> sticker[i][j];
        }
    }

    vector<int> v;
    v.push_back(sticker[0][0]);
    DFS(v, 0, 0);
    v[0] = sticker[1][0];
    DFS(v, 1, 0);

    cout << maxSum << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}