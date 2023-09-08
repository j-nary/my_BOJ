//BOJ_15686 치킨 배달 [골드 5]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

vector<pair<int, int>> zip;  //집
vector<pair<int, int>> chk;  //치킨집
vector<int> nchk;    //남은 치킨집 인덱스

void Combinations(int S, int R, int N, vector<vector<int>>& res, vector<int>& cur) {
    if (R == 0) {
        res.push_back(cur);
        return;
    }

    for (int i = S; i < N; i++) {
        cur.push_back(i);
        Combinations(i + 1, R - 1, N, res, cur);
        cur.pop_back();
    }
}
vector<vector<int>> nCm(int N, int M) {
    vector<vector<int>> res;
    vector<int> cur;
    Combinations(0, M, N, res, cur);
    return res;
}

int dist(int r, int c) {
    int ret = 1e9;
    for (int i = 0; i < nchk.size(); i++) {
        int tmp = abs(chk[nchk[i]].first - r) + abs(chk[nchk[i]].second - c);
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
    vector<vector<int>> Comb = nCm(chk.size(), M);

    int ans = 1e9;
    for (int i = 0; i < Comb.size(); i++) {
        nchk.clear();
        for (int j = 0; j < Comb[i].size(); j++) {
            nchk.push_back(Comb[i][j]);
        }
        int sum = 0;
        for (int i = 0; i < zip.size(); i++) {
            sum += dist(zip[i].first, zip[i].second);
        }
        ans = min(ans, sum);
    }

    cout << ans << '\n';
}