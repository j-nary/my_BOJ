//BOJ_1015 수열 정렬 [실버 4]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,int>> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        v.push_back({input, i});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        v[i].first = v[i].second;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        cout << v[i].second << " ";
    }
    cout << 
}