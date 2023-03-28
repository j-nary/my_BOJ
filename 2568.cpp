//BOJ_2568 전깃줄 - 2 [플래티넘 5]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
vector<int> lis;
bool check[500005];
int path[500005];   //i번째 원소의 LIS에서의 위치
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());

    lis.push_back(v[0].second);
    path[0] = 0;
    for (int i = 1; i < N; i++) {
        if (lis.back() < v[i].second) {
            lis.push_back(v[i].second);
            path[i] = lis.size() - 1;
        } else {
            int idx = upper_bound(lis.begin(), lis.end(), v[i].second) - lis.begin();
            lis[idx] = v[i].second;
            path[i] = idx;
        }
    }

    cout << N - lis.size() << '\n';

    //LIS 원소 check 표시하기
    int len = lis.size() - 1;
    for (int i = N - 1; i >= 0; i--) {
        if (path[i] == len) {
            check[v[i].second] = 1;
            len--;
        }
    }
    //LIS 원소 check 표시 안 된 거 출력하기
    for (int i = 0; i < N; i++) {
        if (check[v[i].second] == 0) {
            cout << v[i].first << '\n';
        }
    }

}