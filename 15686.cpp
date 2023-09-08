//BOJ_15686 치킨 배달 [골드 5]
//예제입력 3번이 반례 -> 이렇게 풀면 안 되는구나
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <cmath>
#include <map>

using namespace std;
struct vnode {
    int dist, cnt;
    int r, c;
};
vector<vnode> v;
vector<pair<int, int>> zip;  //집
vector<pair<int, int>> chk;  //치킨집
pair<int, int> dist(int r, int c) {
    int ret = 1e9;
    vector<int> tmp;
    for (int i = 0; i < zip.size(); i++) {
        tmp.push_back(abs(zip[i].first - r) + abs(zip[i].second - c));
        ret = min(ret, tmp[tmp.size() - 1]);
    }

    int cnt = 0;
    for (int i = 0; i < tmp.size(); i++) {
        if (ret == tmp[i]) cnt++;
    }

    return {ret, cnt};
}

int dist2(int r, int c) {
    int ret = 1e9;
    for (int i = 0; i < v.size(); i++) {
        int tmp = abs(v[i].r - r) + abs(v[i].c - c);
        ret = min(ret, tmp);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int tmp; cin >> tmp;
            if  (tmp == 1) zip.push_back({i, j});
            else if  (tmp == 2) chk.push_back({i, j});
        }
    }

    
    for (int i = 0; i < chk.size(); i++) {
        pair<int, int> tmp = dist(chk[i].first, chk[i].second);
        v.push_back({tmp.first, tmp.second, chk[i].first, chk[i].second});
    }
    sort(v.begin(), v.end(), [](const vnode &a, const vnode &b) {
        if (a.dist == b.dist)
            return a.cnt >= b.cnt;  // dist가 동일하면 cnt로 정렬
        return a.dist <= b.dist;  // 그렇지 않으면 dist로 정렬
    });

    for (int i = v.size() - 1; i >= M; i--) {
        v.erase(v.begin() + i);
    }

    int sum = 0;
    for (int i = 0; i < zip.size(); i++) {
        sum += dist2(zip[i].first, zip[i].second);
    }

    cout << sum << '\n';
}