//BOJ_15686 치킨 배달 [골드 5]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int Map[52][52];
queue<pair<int, int>> zip;  //집
queue<pair<int, int>> chk;  //치킨집

int dist(int r, int c) {
    
    for (int i = 0; i < chk.size(); i++) {

    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == 1) zip.push({i, j});
            else if (Map[i][j] == 2) chk.push({i, j});
        }
    }

    vector<int> ans;
    while(!zip.empty()) {
        int r, c;
        r = zip.front().first;
        c = zip.front().second;
        zip.pop();
        ans.push_back(dist(r, c));
    }

    sort(ans.begin(), ans.end());
    int sum = 0;
    for (int i = 0; i < M; i++) {
        sum += ans[i];
    }

    cout << sum << '\n';
}