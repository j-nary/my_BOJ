//BOJ_1931 회의실 배정 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<pair<int, int>> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int s, e; cin >> s >> e;
        v.push_back({e, s});
    }    
    sort(v.begin(), v.end());

    int cnt = 1;
    int et = v[0].first;
    for (int i = 1; i < N; i++) {
        if (et <= v[i].second)  {   //끝나는 시간이 다음 시작시간보다 빠르면
            cnt++;
            et = v[i].first;
        }
    }

    cout << cnt << '\n';
}