//4 2
//1 2 3 4
//0 1 2 3
//-> 3은 두번째로 인쇄돼
//BOJ_1966 프린터 큐 [실버 3]

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void test_case() {
    int N, M; cin >> N >> M;
    vector<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        q.push_back({tmp, i});
    }

    int cnt = 0;
    while (!q.empty()) {
        int x = q[0].first;
        int y = q[0].second;
        q.erase(q.begin());

        bool flag = 0;
        for (int i = 0; i < q.size(); i++) {
            if (x < q[i].first) {
                q.push_back({x, y});
                flag = 1;
                break;
            }
        }

        if (!flag) {
            cnt++;
            if (y == M) {
                cout << cnt << '\n';
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}