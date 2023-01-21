//https://www.acmicpc.net/problem/1966
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first > b.first;
    else
        return a.second > b.second;
}
void test_case() {
    int N, M; cin >> N >> M;
    vector<pair<int, int> > v;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v.push_back(make_pair(i, tmp));
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first == M) {
            // cout << i + 
        }
    }
    cout << v[M].first + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}