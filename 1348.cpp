//BOJ_1348 주차장 [플래티넘 2]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

char Map[52][52];
vector<pair<int, int>> car;
vector<pair<int, int>> park;
vector<pair<int, int>> depth[101];    //depth[car] = {j, depth}
int park_num[51][51];
bool bfs_chk[51][51];
bool mat_chk[101];
int A[101], B[101];

struct node {
    int r, c;
    int d;
};
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool bfs(int idx) {
    queue<node> q;
    q.push({car[idx].first, car[idx].second, 0});
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int d = q.front().d;
        q.pop();

        if (bfs_chk[r][c]) continue;
        bfs_chk[r][c] = true;
        if (Map[r][c] == 'P') {
            depth[idx].push_back({park_num[r][c], d});
        }

        for (int i = 0; i < 4; i++) {
            int cur_r = r + dir[i][0];
            int cur_c = c + dir[i][1];
            if (Map[cur_r][cur_c] == 'X' || Map[cur_r][cur_c] == '\0') continue;
            q.push({cur_r, cur_c, d + 1});
        }
    }

    return false;
}

bool dfs(int idx, vector<int> v[101]) {
    mat_chk[idx] = true;

    int len = v[idx].size();
    for (int i = 0; i < len; i++) {
        int mat = v[idx][i];
        if (!B[mat] || !mat_chk[B[mat]] && dfs(B[mat], v)) {
            A[idx] = mat;
            B[mat] = idx;
            return true;
        }
    }

    return false;
}
bool bipartite_matching(vector<int> v[101]) {
    int cnt = 0;
    for (int i = 1; i < car.size(); i++) {
        memset(mat_chk, false, sizeof(mat_chk));
        if (dfs(i, v)) cnt++;
    }
    return cnt == car.size() - 1;
}

int bipartite_search() {
    int left = 1, right = 2500;
    int K = 1e9;
    while(left <= right) {
        int mid = (left + right) / 2;
        vector<int> v[101];
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));

        //이분 매칭 그래프 그리기
        for (int i = 1; i < car.size(); i++) {
            for (int j = 0; j < depth[i].size(); j++) {
                if (depth[i][j].second <= mid) {
                    v[i].push_back(depth[i][j].first);
                }
            }
        }

        // 이분 매칭하기
        if (bipartite_matching(v)) {
            right = mid - 1;
            K = min(K, mid);
        } else {
            left = mid + 1;
        }
    }
    
    if (K == 1e9) return -1;
    else return K;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    //입력받기
    int R, C; cin >> R >> C;
    int park_cnt = 1;
    car.push_back({0, 0});
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == 'C')
                car.push_back({i, j});
            if (Map[i][j] == 'P') {
                park.push_back({i, j});
                park_num[i][j] = park_cnt++;
            }
        }
    }

    //예외처리
    if (car.size() - 1 > park.size()) { 
        cout << -1 <<'\n'; return 0;
    }
    if (car.size() - 1 == 0) {
        cout << 0 << '\n'; return 0;
    }

    //car부터 park까지 거리계산해서 depth 배열 채우기
    for (int i = 1; i < car.size(); i++) {
        memset(bfs_chk, false, sizeof(bfs_chk));
        bfs(i);
    }

    cout << bipartite_search() << '\n';
}