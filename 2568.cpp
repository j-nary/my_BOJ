//BOJ_2568 전깃줄 - 2 [플래티넘 5]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
vector<int> lis;
vector<int> path;
bool check[500005];
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
    path.push_back(0);
    for (int i = 1; i < N; i++) {
        if (lis.back() < v[i].second) {
            lis.push_back(v[i].second);
            path.push_back(i);
        } else {
            int idx = upper_bound(lis.begin(), lis.end(), v[i].second) - lis.begin();
            lis[idx] = v[i].second;
            path[idx] = i;
        }
    }
    cout << N - lis.size() << '\n';

    for (int i = 0; i < path.size(); i++) {
        check[path[i]] = 1;
    }
    for (int i = 0; i < N; i++) {
        if (check[i] == 0) {
            cout << v[i].first << '\n';
        }
    }
}